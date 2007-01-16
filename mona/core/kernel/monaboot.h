static unsigned int palette16 [16] = {
	0x040204,
	0x848a84,
	0x4c4a4c,
	0xc4c6c4,
	0x242624,
	0xacaaac,
	0x646664,
	0xeceaec,
	0x141614,
	0xa4a2a4,
	0x3c363c,
	0xd4dad4,
	0xfcfefc,
	0x7c7674,
	0x5c5a5c,
	0xb4bab4,
};

static uint8_t monaboot [105][55] = {
{0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xcc,0xc7,0xcc,0xcc,},
{0xcc,0xcc,0xcc,0xcc,0x7c,0xcc,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,},
{0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x7c,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,},
{0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xc7,0xc7,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x7c,0x77,0x7c,0xcc,0xcc,0xcc,0x7c,0xcc,0xcc,0xcc,},
{0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x77,0x77,0x77,0x7b,0x77,0xb7,0x7b,0x77,0xb7,0x7b,0x77,0xb7,0x7b,0x77,0xb7,0x7b,0x77,0xb7,0x7b,0x77,0xb7,0x7b,0x77,0xb7,0x7b,0x77,0xb7,0x7b,0x77,0xb7,0x7b,0x77,0xb7,0x7b,0x77,0xb7,0x7b,0x77,0x77,0x7b,0x77,0x77,0x7c,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,},
{0xcc,0xcc,0xcc,0xc7,0xcc,0x77,0x77,0x7b,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xb3,0xbb,0x7b,0xb7,0x77,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,},
{0xcc,0xcc,0xcc,0xcc,0xc7,0x77,0xbb,0xb3,0xb3,0x33,0x33,0xf3,0x33,0xf3,0x33,0xf3,0x33,0xf3,0x33,0xf3,0x33,0xf3,0x33,0xf3,0x33,0xf3,0x33,0xf3,0x33,0xf3,0x33,0xf3,0x33,0xf3,0x33,0xf3,0x33,0xf3,0x33,0xf3,0x33,0xf3,0x33,0xf3,0x33,0x33,0x3b,0x3b,0xb7,0x77,0xc7,0xcc,0xcc,0x7c,0xcc,},
{0xcc,0xc7,0xcc,0x7c,0x77,0xbb,0xb3,0x3f,0xff,0x5f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0x3b,0xb7,0x7c,0xcc,0xcc,0xcc,0xcc,},
{0xcc,0xcc,0xcc,0xc7,0x7b,0xbb,0xff,0x9e,0xa8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x8,0xae,0x9f,0xfb,0xbb,0x77,0xc7,0xcc,0xcc,0xcc,},
{0xcc,0xcc,0xcc,0x77,0xbb,0x3f,0x92,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x82,0x9f,0x3b,0xb7,0x7c,0xcc,0xcc,0xcc,},
{0xcc,0xcc,0xc7,0x7b,0xb3,0xfd,0x0,0x0,0x2,0x26,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0xd1,0x19,0xf3,0x0,0x0,0x86,0x33,0xbb,0x77,0xcc,0xcc,0xcc,},
{0xcc,0x7c,0x77,0xbb,0x3f,0x68,0x0,0x4a,0xee,0xdd,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x95,0xf3,0x93,0xf0,0x0,0xe3,0x3b,0xb7,0x7c,0xcc,0xcc,},
{0xcc,0xcc,0x77,0xb3,0xfd,0x0,0x8,0x8a,0x15,0x55,0xff,0xf5,0xf5,0xf5,0xf5,0xf5,0xf9,0xf9,0xf9,0xf9,0xf9,0xf9,0xf9,0xf9,0xf9,0xf9,0xf9,0xf9,0xf9,0xf9,0xf9,0xf9,0xf9,0xf9,0xf9,0xf9,0xf9,0xf9,0xf9,0xf5,0xf5,0xf5,0xf5,0xff,0xf5,0xff,0xf3,0x91,0x0,0xd,0xf3,0xb7,0x7c,0x7c,0xcc,},
{0xcc,0xc7,0x7b,0x33,0x98,0x0,0x88,0x41,0x55,0xf5,0xff,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x3f,0xff,0x55,0x99,0x90,0x8,0x93,0x3b,0x77,0xcc,0xcc,},
{0xcc,0xc7,0x7b,0x3f,0x20,0x8,0x8a,0x95,0xf5,0x3b,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xb3,0x3f,0xf5,0x55,0x91,0x0,0xe5,0xbb,0x77,0xcc,0xcc,},
{0xcc,0xc7,0xbb,0x39,0x48,0x8,0x49,0x9f,0x3b,0xbb,0x7b,0x77,0xb7,0x7b,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0xb7,0x7b,0x7b,0x7b,0xbb,0x35,0xf5,0x99,0x90,0x89,0x3b,0xb7,0x7c,0xcc,},
{0xcc,0x77,0x73,0xfd,0x88,0x8,0x15,0xf3,0xbb,0xb7,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x7b,0xbb,0xb3,0xf5,0x51,0x10,0x6,0xfb,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0xfd,0xa0,0xa,0x9f,0x3b,0xb7,0x77,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0x77,0xbb,0x3f,0x91,0x6e,0x4,0x33,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0xfe,0x20,0xd,0x5f,0xbb,0x77,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x7c,0xcc,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0x7b,0x33,0xf9,0x66,0x8,0x5b,0xbb,0x7c,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0x89,0xf3,0xbb,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0x7c,0xcc,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x77,0xb3,0xff,0x11,0x0,0xf3,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0x92,0x20,0x45,0xf3,0xb7,0x7c,0xcc,0xcc,0xcc,0xcc,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xb3,0xf5,0x1e,0x0,0xf3,0xb7,0x7c,0xcc,},
{0xcc,0x7b,0xb3,0xf2,0x20,0xa5,0x33,0x37,0xcc,0x7c,0xcc,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xc7,0xcc,0xcc,0xcc,0x7c,0xcc,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xc7,0xcc,0x77,0xbb,0x3f,0xd2,0x0,0xff,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0xfb,0xb7,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0x7b,0xff,0xd2,0x0,0xf3,0xb7,0x77,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0x3b,0x77,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xbb,0x3f,0xd2,0x0,0x53,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0x92,0x20,0xaf,0x3b,0xb7,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0x7c,0xcc,0xcc,0xd7,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x35,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0x7b,0x35,0xd2,0x0,0xf3,0xb7,0x7c,0xcc,},
{0xcc,0x7b,0xb3,0xf2,0x20,0xa5,0x3b,0x77,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0x8d,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xa2,0xcc,0xcc,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xc7,0x7b,0x3f,0xd2,0x0,0x53,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0x3b,0x77,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcd,0x8,0x7c,0xcc,0xcc,0xcc,0x7c,0xcc,0x7c,0xcc,0xcc,0xc5,0x0,0xfc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x7c,0xcc,0x7c,0xcc,0xcc,0xc7,0x7b,0x3f,0xd2,0x0,0xf3,0xbb,0x7c,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0x3b,0x77,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc4,0x80,0x9c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xce,0x80,0xec,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xbb,0x3f,0xd2,0x0,0x53,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0x92,0x20,0xaf,0x3b,0xb7,0xcc,0xcc,0xcc,0x7c,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xcc,0x90,0x58,0x4c,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x70,0xd2,0xb,0xcc,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0x7b,0x35,0xd2,0x0,0xf3,0xb7,0x7c,0xcc,},
{0xcc,0x7b,0xb3,0xf2,0x20,0xa9,0x3b,0x77,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0x4a,0xcd,0x9,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xe0,0x7f,0xe,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0x7b,0x3f,0xd2,0x0,0xff,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0x3b,0x77,0xcc,0x7c,0xcc,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xc9,0x9,0xcb,0xa,0xcc,0xcc,0xcc,0xcc,0x7c,0xcc,0xcc,0xc7,0xe,0xcc,0x40,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0x7b,0x3f,0xd2,0x0,0xf3,0xb7,0x77,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0x3b,0x77,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc2,0x4c,0xcc,0xe0,0x5c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcd,0x7,0xc7,0x90,0xdc,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xc7,0xcc,0xc7,0xc7,0xbb,0x3f,0xd2,0x0,0x53,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0x92,0x20,0xaf,0x3b,0xb7,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xf0,0x1c,0xc7,0x70,0x2c,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0x78,0x2c,0xcc,0xc4,0x87,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0x7b,0x35,0xd2,0x0,0xf3,0xb7,0x7c,0xcc,},
{0xcc,0x7b,0xb3,0xf2,0x20,0xa5,0x3b,0x77,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x7c,0xcc,0x7c,0xe8,0x7c,0xcc,0xca,0xb,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0x90,0x3c,0xcc,0xcd,0x9,0xcc,0xcc,0xcc,0xcc,0xcc,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0x7b,0x3f,0xd2,0x0,0x53,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0x3b,0x77,0xcc,0xc7,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xd,0xcc,0xcc,0xc3,0xe,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x4a,0xcc,0xcc,0xc7,0x84,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0x7b,0x3f,0xd2,0x0,0xf3,0xbb,0x7c,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0x3b,0x77,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xce,0xb,0xcc,0xcc,0xcc,0xa0,0x7c,0xcc,0xcc,0xcc,0xcc,0xc9,0x9,0xc7,0xcc,0xcc,0x60,0x9c,0xcc,0xcc,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xbb,0x3f,0xd2,0x0,0x53,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0x92,0x20,0xaf,0x3b,0xb7,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xcc,0xcc,0x70,0xec,0xcc,0xcc,0xcc,0x90,0xdc,0xcc,0xc7,0xcc,0xcc,0xca,0x4c,0xcc,0xcc,0xcc,0x70,0xac,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xc7,0xcc,0xc7,0xcc,0xc7,0x7b,0x35,0xd2,0x0,0xf3,0xb7,0x7c,0xcc,},
{0xcc,0x7b,0xb3,0xf2,0x20,0xa5,0x3b,0x77,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x50,0x7c,0xc7,0xcc,0xcc,0xc8,0xdc,0xcc,0xcc,0xcc,0xcc,0xb8,0x9c,0xcc,0xcc,0xcc,0xc2,0x2c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0x7b,0x3f,0xd2,0x0,0xff,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0x3b,0x77,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xcb,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x77,0x7b,0x3f,0xd2,0x0,0xf3,0xb7,0x77,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0x3b,0x77,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0xcc,0x7c,0xcc,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xbb,0x3f,0xd2,0x0,0x53,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0x92,0x20,0xaf,0x3b,0xb7,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xfd,0x1c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcb,0xdd,0x7c,0xcc,0xcc,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0x7b,0x35,0xd2,0x0,0xf3,0xb7,0x7c,0xcc,},
{0xcc,0x7b,0xb3,0xf2,0x20,0xa9,0x3b,0x77,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc3,0xa,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xa0,0x2c,0xcc,0xcb,0x89,0xcc,0xcc,0xc7,0xcc,0xc7,0xcc,0xc7,0xcc,0xc7,0x7b,0x3f,0xd2,0x0,0x53,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0x3b,0x77,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x38,0x27,0xcc,0xcc,0xc7,0xdc,0xcc,0xcc,0xcc,0xcc,0xdb,0xcc,0xcc,0x72,0xe,0xcc,0x7c,0x28,0x3c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0x7b,0x3f,0xd2,0x0,0xf3,0xbb,0x7c,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0x3b,0x77,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xc7,0xcc,0xdd,0xcc,0x7c,0xcc,0xc2,0x9,0xcc,0xcc,0xcc,0xcd,0x9,0xcc,0xcc,0xcc,0x62,0x7c,0xcc,0xca,0x2c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xbb,0x3f,0xd2,0x0,0x53,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0x92,0x20,0xaf,0x3b,0xb7,0xcc,0xcc,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x77,0x4,0x7c,0xcc,0xcc,0x78,0xac,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xf,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0x7b,0x35,0xd2,0x0,0xf3,0xb7,0x7c,0xcc,},
{0xcc,0x7b,0xb3,0xf2,0x20,0xaf,0xfb,0x77,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xe0,0x0,0x0,0x0,0x0,0xfc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xad,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xc7,0x7b,0x3f,0xd2,0x0,0xff,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0x3b,0x77,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x7c,0xcc,0xcc,0xcc,0xcc,0x78,0xd,0xdd,0x1d,0xe,0xcc,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xd2,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0x7b,0x3f,0xd2,0x0,0xf3,0xb7,0x77,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0x3b,0x77,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcd,0xd,0xcc,0xce,0x7,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xcc,0xcc,0x14,0xc7,0xcc,0xc7,0xcc,0xc7,0xcc,0xcc,0xc7,0xbb,0x3f,0xd2,0x0,0x53,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0x92,0x20,0xaf,0x3b,0x77,0xcc,0x7c,0xcc,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x7c,0xcc,0xcc,0x77,0x88,0x7c,0xb0,0xdc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0x9a,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0x7b,0x35,0xd2,0x0,0xf3,0xb7,0x7c,0xcc,},
{0xcc,0x7b,0xb3,0xf2,0x20,0xa9,0x3b,0x77,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x7c,0xcc,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x90,0xec,0x28,0x7c,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xd2,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0x7b,0x3f,0xd2,0x0,0x53,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0x3b,0xb7,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc4,0x1,0xd,0xcc,0xcc,0xcc,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xed,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x7c,0xc7,0x7b,0x3f,0xd2,0x0,0xf3,0xbb,0x7c,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0x3b,0x77,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xcc,0xc7,0xcc,0xcc,0xcf,0x0,0x4c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x7c,0xcc,0xc7,0x3,0xcc,0xcc,0x7c,0xcc,0xcc,0xcc,0xcc,0xc7,0xbb,0x3f,0xd2,0x0,0x53,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0x92,0x20,0xaf,0x3b,0x77,0xcc,0xc7,0xc7,0x7c,0xcc,0x7c,0xcc,0xcc,0x7c,0xcc,0xc7,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x20,0x9c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcd,0xec,0xcc,0xcc,0xcc,0xcc,0x7c,0xcc,0xcc,0xc7,0x7b,0x35,0xd2,0x0,0xf3,0xb7,0x7c,0xcc,},
{0xcc,0x7b,0xb3,0xf2,0x20,0xa5,0x3b,0x77,0x7c,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xfa,0xcc,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x30,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x77,0x7b,0x3f,0xd2,0x0,0xff,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0x3b,0x77,0x7c,0xc7,0x77,0x77,0xcc,0x7c,0xcc,0xcc,0xcc,0xcc,0x77,0x77,0x7c,0xc7,0x7c,0xcc,0xcc,0xcc,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcb,0x89,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xc7,0x7b,0x3f,0xd2,0x0,0xf3,0xb7,0x77,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0x3b,0x77,0x77,0x77,0x77,0x77,0x77,0xcc,0xcc,0x7c,0xc7,0xc7,0x77,0x77,0x77,0x77,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xc7,0xcc,0xc7,0x9c,0xc7,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0x7b,0x35,0xd2,0x0,0x53,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0x92,0x20,0xaf,0x3b,0xb7,0x77,0x77,0x77,0x77,0x77,0x7c,0xcc,0xcc,0xcc,0x77,0x7b,0x7b,0xb7,0x77,0x7c,0xcc,0xbc,0xcc,0xcc,0xcc,0xc7,0x7c,0xc7,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xcc,0xcc,0xc7,0x7b,0x3f,0xd2,0x0,0xf3,0xb7,0x7c,0xcc,},
{0xcc,0x7b,0xb3,0xf2,0x20,0xaf,0x3b,0xb7,0x77,0x77,0xbb,0xbb,0x77,0x7c,0x7c,0xc7,0xc7,0x77,0xbb,0xbb,0xbb,0x77,0x77,0x77,0xc7,0xc7,0x77,0x77,0x7c,0xcc,0x7c,0xcc,0xcc,0xc7,0xcc,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x7c,0xcc,0xc7,0xbb,0x3f,0xd2,0x0,0x53,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0x3b,0xb7,0x7a,0xaa,0x6b,0xbb,0xb7,0x77,0xc7,0xcc,0x77,0x79,0x4a,0xa1,0xbb,0xb7,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0xc7,0x77,0x77,0xcc,0xcc,0xcc,0x7c,0xc7,0xc7,0xcc,0xc7,0xc7,0x77,0x7c,0xc7,0xcc,0x77,0x7b,0x3f,0xd2,0x0,0xf3,0xbb,0x7c,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xa5,0x3b,0x7b,0x70,0x0,0x9,0xbb,0xbb,0x77,0x7c,0x7c,0x77,0xf8,0x0,0x6,0xbb,0xb7,0x77,0x77,0x7b,0x77,0xb7,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0xc7,0xc7,0xc7,0xcc,0x7c,0x7c,0x77,0x77,0x77,0x7c,0x7c,0xc7,0x7b,0x35,0xd2,0x0,0x53,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0x92,0x20,0xaf,0x3b,0xb7,0x70,0x0,0x8,0x33,0xbb,0xb7,0x77,0x77,0x77,0xa0,0x88,0x6,0xbb,0xbb,0x77,0x77,0x7b,0x7b,0x7b,0x7b,0x77,0x7b,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0xc7,0xc7,0xc7,0x77,0x77,0x77,0x77,0xcc,0x77,0x7b,0x3f,0xd2,0x0,0xf3,0xb7,0x7c,0xcc,},
{0xcc,0x7b,0xb3,0xf2,0x20,0xaf,0x3b,0xb7,0x70,0x84,0x40,0xe3,0x3b,0xbb,0x77,0x77,0x7d,0x8,0x22,0x46,0x3b,0xbb,0x7b,0xbb,0x7b,0xb7,0xbb,0xbb,0x7b,0xb7,0xbb,0xbb,0xb7,0xb7,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x7b,0x7b,0xbb,0x77,0x7c,0x77,0x7b,0x3f,0xd2,0x0,0xff,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0x3b,0xb7,0x74,0x41,0xea,0x9,0xbb,0xbb,0xb7,0x77,0xf8,0x8,0x52,0x46,0x3b,0xbb,0xfe,0xaa,0xaa,0xaa,0xaa,0xe3,0xb7,0xbf,0xaa,0xeb,0xbb,0xbb,0x77,0x7a,0xaf,0x77,0x77,0x77,0x7b,0xaa,0xdb,0xbb,0xb7,0x77,0x77,0x7b,0x3f,0xd2,0x0,0xf3,0xb7,0x77,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xa9,0x3b,0xb7,0x74,0xa1,0x3e,0x44,0x3b,0xbb,0xbb,0xbb,0xa0,0x2,0x32,0x4d,0xbb,0xb3,0x80,0x88,0x88,0x44,0x44,0x88,0x5b,0xb9,0x8,0x8e,0xbb,0xbb,0x7b,0xb0,0x9,0xbb,0xb7,0x77,0x7e,0x8,0x8f,0xbb,0xbb,0x77,0x77,0xbb,0x3f,0xd2,0x0,0x53,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0x92,0x20,0xaf,0x3b,0xb7,0x74,0x8d,0xb9,0x28,0xeb,0xbb,0xbb,0xbd,0x0,0x83,0xba,0x4d,0xbb,0xb2,0xa,0x11,0x19,0x99,0x99,0x28,0x2b,0xb5,0x8a,0x2a,0xeb,0xbb,0xb7,0xb0,0x9,0xb7,0x77,0x77,0x90,0x8a,0x42,0x3b,0xbb,0x77,0x77,0xbb,0x35,0xd2,0x0,0xf3,0xb7,0x7c,0xcc,},
{0xcc,0x7b,0xb3,0xf2,0x20,0xaf,0x3b,0xb7,0xb4,0xd,0xbb,0xda,0x9,0xbb,0xbb,0x58,0x0,0x1b,0xb4,0x86,0xbb,0xba,0x5,0xbb,0xb7,0xbb,0xbb,0x18,0x4b,0xb9,0x8e,0x96,0xaa,0x3b,0xbb,0xb0,0x9,0xbb,0xbb,0xbb,0xa0,0x49,0xa0,0x93,0xbb,0xb7,0x77,0xbb,0x3f,0xd2,0x0,0x53,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0x3b,0xb7,0x74,0x8d,0xb7,0xb2,0x44,0x3b,0xbb,0xa0,0xa,0xbb,0xb4,0x86,0xbb,0xb2,0x9,0x7b,0x7b,0x7b,0x7b,0xd0,0xab,0xbf,0x8a,0xb3,0xea,0xa3,0xbb,0xb0,0x9,0xbb,0x7b,0x71,0x0,0xdb,0x64,0x43,0xbb,0xb7,0x77,0xbb,0x3f,0xd2,0x0,0xf3,0xbb,0x7c,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0x3b,0xb7,0x74,0xd,0xbb,0xb9,0xa8,0xeb,0xbd,0x0,0x3,0xbb,0xb8,0x8d,0xbb,0x72,0x89,0xbb,0xbb,0xb7,0xbb,0x18,0xab,0xbf,0xa,0x7b,0x32,0x8a,0x3b,0xb8,0x9,0xb7,0xbb,0xb8,0xa,0xb3,0xf4,0x6,0xbb,0xb7,0xb7,0xbb,0x3f,0xd2,0x0,0x53,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0x52,0x20,0xaf,0x3b,0xb7,0x78,0x8d,0x77,0xb7,0xea,0x5,0xf8,0x0,0xd7,0xbb,0x74,0xd,0xbb,0xb2,0x89,0x7b,0x7b,0x7b,0xb7,0xd0,0xab,0xb3,0x8a,0xbb,0xbf,0x24,0xa3,0x70,0x9,0xbb,0x7b,0x68,0x8e,0xdd,0x1e,0x48,0xf7,0xb7,0x77,0xbb,0x3f,0xd2,0x0,0xf3,0xb7,0x7c,0xcc,},
{0xcc,0x7b,0xb3,0xf2,0x20,0xa5,0x3b,0xb7,0x74,0x8d,0x77,0x77,0xb2,0x4a,0x20,0x8a,0xbb,0x77,0x78,0x8d,0x77,0x76,0x45,0xb7,0xbb,0xb7,0xbb,0xd0,0xa7,0xbf,0x8a,0x77,0x77,0xfe,0x48,0x50,0x9,0x7b,0xb3,0x8,0xa2,0x4a,0xed,0x6a,0x2b,0x77,0x77,0xbb,0x3f,0xd2,0x0,0xff,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0x3b,0xb7,0x74,0x4d,0x77,0x77,0x79,0x66,0x24,0x3,0x77,0x77,0x74,0x4d,0x77,0x71,0x2d,0x55,0x99,0x99,0x99,0x40,0x27,0x73,0x8a,0x77,0x77,0x77,0x2a,0xa8,0x9,0xb7,0x7a,0x84,0xdd,0xdd,0x99,0x96,0xa5,0x77,0x77,0xbb,0x3f,0xd2,0x0,0xf3,0xb7,0x77,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0x3b,0x77,0xca,0x86,0x77,0x7c,0x77,0x91,0x6a,0x17,0x77,0x7c,0x7a,0x8d,0x7c,0x7b,0xd6,0xa4,0x44,0x44,0x88,0x80,0x97,0x73,0x4a,0x77,0xc7,0xc7,0x7d,0xea,0x8f,0x77,0x94,0x85,0x77,0x77,0x77,0x75,0xd2,0xc7,0x77,0xbb,0x3f,0xd2,0x0,0x53,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0x92,0x20,0xaf,0x3b,0x77,0x7a,0x8d,0x7c,0x7c,0x7c,0x36,0x22,0x77,0xc7,0xc7,0xc4,0x8d,0x77,0x77,0x31,0x22,0xaa,0xaa,0xa4,0xa9,0x77,0x7b,0x8a,0x7c,0x7c,0x7c,0x77,0x6a,0x43,0x77,0x44,0x6c,0x7c,0x77,0x77,0x77,0x1a,0xd7,0x77,0xbb,0x35,0xd2,0x0,0xf3,0xb7,0x7c,0xcc,},
{0xcc,0x7b,0xb3,0xf2,0x20,0xa5,0x3b,0x77,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0x7c,0x7c,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0x77,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x77,0x77,0xc7,0xc7,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xbb,0x3f,0xd2,0x0,0x53,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0x3b,0x77,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xc7,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x77,0x7b,0x3f,0xd2,0x0,0xf3,0xbb,0x7c,0xcc,},
{0xc7,0x77,0xb3,0xf2,0x20,0xaf,0x33,0x77,0xcc,0xcc,0xc7,0xcc,0xc7,0xcc,0xc7,0xcc,0xc7,0xcc,0xc7,0xcc,0xc7,0xcc,0xc7,0xcc,0xc7,0xcc,0xc7,0xcc,0xc7,0xcc,0xc7,0xcc,0xc7,0xcc,0xc7,0xcc,0xc7,0xcc,0xc7,0xcc,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0x7b,0x3f,0xd2,0x0,0x53,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0x52,0x20,0xaf,0x3b,0x77,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0xcc,0xcc,0xc7,0x7b,0x35,0xd2,0x0,0xf3,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0x3b,0x77,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xcc,0x77,0x7b,0x3f,0xd2,0x0,0xff,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0x52,0x20,0xaf,0x3b,0x77,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0x7b,0xff,0xd2,0x0,0xf3,0xb7,0x77,0xcc,},
{0xcc,0x7b,0xb3,0xf2,0x20,0xa5,0x3b,0x77,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0x7b,0x3f,0xd2,0x0,0x53,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0x3b,0xb7,0xc7,0xcc,0xcc,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0xcc,0xcc,0xc7,0x7b,0x3f,0xd2,0x0,0xf3,0xb7,0x7c,0xcc,},
{0xc7,0x77,0xb3,0xf2,0x20,0xaf,0x3b,0x77,0xcc,0xcc,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x77,0x7b,0x3f,0xd2,0x0,0x53,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0x52,0x20,0xaf,0x3b,0x77,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x7c,0xcc,0xc7,0x7b,0x3f,0xd2,0x0,0xf3,0xbb,0x7c,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0xaf,0x5b,0x77,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xbb,0xff,0xd2,0x0,0x53,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xbf,0xf2,0x20,0xaf,0x3b,0xb7,0xcc,0xcc,0xcc,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0xbb,0x3f,0xd2,0x0,0xf3,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0x52,0x20,0xa5,0xfb,0xb7,0x7c,0xcc,0xcc,0xcc,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0x7c,0xcc,0xcc,0x77,0x73,0xf5,0xea,0x0,0xf3,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xbb,0xf2,0x20,0x49,0xf3,0xb7,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x77,0xb3,0xf9,0x48,0x0,0xf3,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0xf2,0x20,0x81,0xf3,0xbb,0x7c,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc7,0x7b,0xb3,0xf9,0x48,0x0,0xfb,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xb3,0x3d,0xe0,0xe,0x5f,0x3b,0xb7,0x7c,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xcc,0x77,0xbb,0x3f,0x5d,0x40,0xa,0xf3,0xb7,0x7c,0xcc,},
{0xcc,0x77,0xbb,0xf9,0x6d,0x4,0x9f,0x33,0xbb,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0xb3,0x3f,0x94,0x80,0x6,0xfb,0xb7,0x7c,0xcc,},
{0xcc,0xc7,0xbb,0x3f,0x11,0x0,0x25,0xf3,0x3b,0xbb,0xb7,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0xbb,0xbb,0xbf,0xf5,0xe0,0x0,0x49,0x3b,0xb7,0xcc,0xcc,},
{0xcc,0xc7,0x7b,0x3f,0x5d,0x10,0xd,0x5f,0xf3,0x3b,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xb3,0xff,0xf6,0x80,0x0,0x2f,0x3b,0x77,0xcc,0xcc,},
{0xcc,0xc7,0x7b,0x33,0xf1,0x90,0x8,0x65,0x5f,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0xff,0xf5,0x68,0x0,0x8,0x93,0x3b,0x77,0xcc,0xcc,},
{0xcc,0x7c,0x77,0xbb,0xf9,0x99,0x0,0x2,0x15,0x5f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x55,0x1a,0x0,0x0,0xd,0xfb,0xb7,0x7c,0xcc,0xcc,},
{0xcc,0xcc,0x77,0xbb,0x33,0xf9,0x90,0x0,0xa,0x2d,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x1d,0xea,0x0,0x0,0x80,0xe5,0x3b,0xb7,0x7c,0x7c,0xcc,},
{0xcc,0xcc,0xc7,0x7b,0xb3,0xff,0x9b,0x90,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xe2,0xad,0x33,0xbb,0x77,0xcc,0xcc,0xcc,},
{0xcc,0xcc,0xc7,0x77,0xbb,0x33,0x53,0xf9,0x11,0x1d,0x11,0xd1,0x1d,0x11,0xd1,0x1d,0x11,0xd1,0x1d,0x11,0xd1,0x1d,0x11,0xd1,0x1d,0x11,0xd1,0x1d,0x11,0xd1,0x1d,0x11,0xd1,0x1d,0x11,0xd1,0x1d,0x11,0xd1,0x1d,0x11,0xd1,0x1d,0x11,0xd1,0x11,0x1d,0xe1,0x9f,0x3b,0xb7,0x77,0xcc,0xcc,0xcc,},
{0xcc,0xcc,0xcc,0xc7,0x7b,0xb3,0x3f,0x3f,0x91,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x99,0xff,0x33,0xbb,0x77,0x7c,0xcc,0xcc,0xcc,},
{0xcc,0xcc,0xcc,0xc7,0x77,0xbb,0xbb,0xf3,0xff,0xf9,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xf5,0xff,0xff,0x33,0xbb,0xb7,0x7c,0xcc,0xcc,0xcc,0xcc,},
{0xcc,0xcc,0xcc,0xcc,0xcc,0x77,0xbb,0xb3,0xb3,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x3b,0x3b,0xb7,0x77,0xcc,0xcc,0xcc,0xcc,0xcc,},
{0xcc,0xcc,0xcc,0xcc,0xc7,0x77,0x77,0x7b,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xb7,0x77,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,},
{0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x7c,0x77,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,},
{0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0xc7,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,},
{0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,},
{0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,},
};
