#include <stdio.h>
#include <Windows.h>
#include "x265dll.h"
#include "x265.h"



byte g_pbbitstreambuffer[1024 * 1024 * 10];
byte g_pbyuvbuffer[1920 * 1088 * 3 / 2];
int g_inalnum;
int g_pinallength[10];

void* ph1;

void test_encoder() {

	char* cfg = (char *)"encoder_config_hd.cfg";
	
	

	x265_encoder_init(&ph1,1,cfg);

	FILE* fp = fopen("e:\\huibao\\video_capture\\video_capture_project\\video_capture_ffmpeg\\output.yuv", "rb");

	int i;
	int iret;
	for (i = 0; i < 25; i++)
	{
		iret = fread(g_pbyuvbuffer, 1, 1920 * 1088 * 3 / 2, fp);
		if (iret != 1920 * 1088 * 3 / 2) {
			printf("read buffer failed!\n");
			break; ;
		}
		x265_encode(ph1,g_pbbitstreambuffer,&g_inalnum, g_pinallength, g_pbyuvbuffer);
	}

	fclose(fp);

	x265_encoder_free(ph1);

	printf("hello, world!\n");
	return ;
}