/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 01:52:11 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/02 18:56:05 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include "game.h"

#define LCG_A 1664525
#define LCG_C 1013904223
#define LCG_M 4294967296

static double	lcg_random(int seed)
{
	seed = (LCG_A * seed + LCG_C) % LCG_M;
	return ((double)seed / LCG_M);
}

double	rand_normal(double mean, double stddev, int use_last, int seed)
{
	double			u1;
	double			u2;
	double			z1;
	static double	z2;

	if (use_last)
	{
		use_last = 0;
		return (z2 * stddev + mean);
	}
	u1 = lcg_random(seed);
	u2 = lcg_random(seed);
	z1 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
	z2 = sqrt(-2.0 * log(u1)) * sin(2.0 * M_PI * u2);
	use_last = 1;
	return (z1 * stddev + mean);
}

int	read_rand(int min, int max)
{
	int	fd;
	int	buf;

	fd = open("/dev/random", O_RDONLY);
	if (fd == -1)
	{
		perror("Open");
		return (0);
	}
	if (read(fd, &buf, sizeof(int)) == -1)
	{
		perror("Read");
		return (0);
	}
	close(fd);
	return (min + (buf & 0x7FFFFFFF) % (max - min));
}