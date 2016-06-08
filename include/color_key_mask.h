/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_key_mask.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 17:43:21 by dboudy            #+#    #+#             */
/*   Updated: 2016/06/08 15:53:35 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_KEY_MASK_H
# define COLOR_KEY_MASK_H

# define BLACK		0x000000
# define BROWN		0x663300
# define GREY		0x7F7F7F
# define WHITE		0xFFFFFF
# define RED		0xFF0000
# define ORANGE		0xFFBC00
# define YELLOW		0xFFFF00
# define GREEN		0x00FF00
# define GREENF		0xBBFFBB
# define CYAN		0x33FFFF
# define BLUE		0x11AAFF
# define BLUEF		0x1111FF
# define PINK		0xED22ED
# define SALMON		0xFF7F7F
# define PURPLE 	0x882289

# define ECHAP		53
# define ENTER		36
# define DEL		51
# define UP			126
# define DOWN		125
# define LEFT		123
# define RIGHT		124
# define W			13
# define A			0
# define S			1
# define D			2
# define Q			12
# define E			14
# define LESS		78
# define MORE		69
# define SPACE		49
# define ONE		83
# define TWO		84
# define THREE		85
# define FOUR		86
# define FIVE		87
# define ONE2		18
# define TWO2		19
# define THREE2		20

# define KEYPRESSM		(1L<<0)
# define KEYRELEASEM	(1L<<1)
# define BUTPRESSM		(1L<<2)
# define BUTRELEASEM	(1L<<3)
# define ENTERWM		(1L<<4)
# define LEAVEWM		(1L<<5)
# define BUT1MOTIONM	(1L<<8)
# define BUT2MOTIONM	(1L<<9)
# define BUT3MOTIONM	(1L<<10)
# define BUT4MOTIONM	(1L<<11)
# define BUT5MOTIONM	(1L<<12)
# define BUTMOTIONM		(1L<<13)

# define KEYPRESS		2
# define KEYRELEASE		3
# define BUTTONPRESS	4
# define BUTTONRELEASE	5
# define MOTIONOTIFY	6
# define FOCUSIN		9
# define FOCUSOUT		10
# define EXPOSE			12
# define GRAPHICSEXPOSE	13
# define NOEXPOSE		14
# define LASTEVENT		35

#endif
