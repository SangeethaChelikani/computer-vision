/*
 ============================================================================
 Name        : vision_app_gui.c
 Author      : geetha
 Version     :
 Copyright   : Your copyright notice
 Description : vision -C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <gtk/gtk.h>
#include <string.h>
#include <gtk/gtkx.h>
#include <gdk/gdk.h>
#include <vlc/vlc.h>
#include "vision_app_gui.h"
#include <Python.h>
#include <json.h>


pthread_t thread1;
pthread_t thread2,thread3;

libvlc_instance_t * inst;
libvlc_media_player_t *mp;
libvlc_media_t *m;

void read_thelogfile(char *logfile) {
	FILE *fp;
	printf("/root/eclipse-workspace/vision_app_gui/Debug/log.txt");
	fp = fopen("/root/eclipse-workspace/vision_app_gui/Debug/log.txt", "r"); // read mode
	if (fp == NULL) {
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}
	// printf("The contents of %s file are:\n", file_name);
	while ((logfile = fgetc(fp)) != EOF)
		printf("%c", logfile);
	fclose(fp);
	//return 0;
}
G_MODULE_EXPORT
//void on_w_home_fkey1_debug_clicked(GtkButton *button, app_widgets *widgets) {
void on_w_home_fkey1_debug_clicked() {
	GtkTextIter iter,start,end;
	gchar *array;
	gchar *utf8;
	GError *err = NULL;
	gsize *bytes_read = NULL;
	gsize *bytes_written = NULL;
	gsize length;
	g_print("on_w_home_debug_fkey1_clicked\n");
	memset(&array,0x00,sizeof(array));
	//char logfile[4000];
	//read_thelogfile(&logfile);
	gint active_item = gtk_combo_box_get_active(
			GTK_COMBO_BOX(widgets->w_logfile_sel));
	printf("%d\n", active_item);

	if (active_item == 0) {
		memset(&array,0x00,sizeof(array));
		//g_file_get_contents(
			//	"/root/eclipse-workspace/vision_app_gui/Debug/log.txt", &array,&length, NULL);
		g_file_get_contents("/home/pi/Desktop/Data/87887d23b148467fb20bec81a16b5e75/logs/edge.log", &array,&length, NULL);

		utf8 = g_convert(array, length, "UTF-8", "us-ascii", bytes_read,bytes_written, &err);
		if (err != NULL) {
			printf("G_CONVERT(!NULL) error -->\n");
			g_error_free(err);
		}
	} else if (active_item == 1) {
		memset(&array,0x00,sizeof(array));
		//g_file_get_contents(
				//"/root/eclipse-workspace/vision_app_gui/Debug/log1.txt", &array,&length, NULL);
		g_file_get_contents("/home/pi/Desktop/Data/87887d23b148467fb20bec81a16b5e75/logs/upload.log", &array,&length, NULL);
		utf8 = g_convert(array, length, "UTF-8", "us-ascii", bytes_read,bytes_written, &err);
		if (err != NULL) {
			printf("G_CONVERT(!NULL) error -->\n");
			g_error_free(err);
		}
	} else if (active_item == 2) {
		memset(&array,0x00,sizeof(array));
		//g_file_get_contents("/root/eclipse-workspace/vision_app_gui/Debug/log2.txt", &array,&length, NULL);
		g_file_get_contents("/home/pi/Desktop/Data/87887d23b148467fb20bec81a16b5e75/logs/device_monitor.log", &array,&length, NULL);

		utf8 = g_convert(array, length, "UTF-8", "us-ascii", bytes_read,bytes_written, &err);
		if (err != NULL) {
			printf("G_CONVERT(!NULL) error -->\n");
			g_error_free(err);
		}
	}else if (active_item == 3) {
		memset(&array,0x00,sizeof(array));
		//g_file_get_contents("/root/eclipse-workspace/vision_app_gui/Debug/log2.txt", &array,&length, NULL);
		g_file_get_contents("/home/pi/Desktop/Data/87887d23b148467fb20bec81a16b5e75/logs/camera.log", &array,&length, NULL);

		utf8 = g_convert(array, length, "UTF-8", "us-ascii", bytes_read,bytes_written, &err);
		if (err != NULL) {
			printf("G_CONVERT(!NULL) error -->\n");
			g_error_free(err);
		}
	}else if (active_item == 4) {
		memset(&array,0x00,sizeof(array));
		//g_file_get_contents("/root/eclipse-workspace/vision_app_gui/Debug/log2.txt", &array,&length, NULL);
		g_file_get_contents("/home/pi/Desktop/Data/87887d23b148467fb20bec81a16b5e75/logs/boot.log", &array,&length, NULL);

		utf8 = g_convert(array, length, "UTF-8", "us-ascii", bytes_read,bytes_written, &err);
		if (err != NULL) {
			printf("G_CONVERT(!NULL) error -->\n");
			g_error_free(err);
		}
	}else if (active_item == 5) {
		memset(&array,0x00,sizeof(array));
		//g_file_get_contents("/root/eclipse-workspace/vision_app_gui/Debug/log2.txt", &array,&length, NULL);
		g_file_get_contents("/home/pi/Desktop/Data/87887d23b148467fb20bec81a16b5e75/logs/gpio_led.log", &array,&length, NULL);

		utf8 = g_convert(array, length, "UTF-8", "us-ascii", bytes_read,bytes_written, &err);
		if (err != NULL) {
			printf("G_CONVERT(!NULL) error -->\n");
			g_error_free(err);
		}
	}else if (active_item == 6) {
		memset(&array,0x00,sizeof(array));
		//g_file_get_contents("/root/eclipse-workspace/vision_app_gui/Debug/log2.txt", &array,&length, NULL);
		g_file_get_contents("/home/pi/Desktop/Data/87887d23b148467fb20bec81a16b5e75/logs/ModemMonitor.log", &array,&length, NULL);

		utf8 = g_convert(array, length, "UTF-8", "us-ascii", bytes_read,bytes_written, &err);
		if (err != NULL) {
			printf("G_CONVERT(!NULL) error -->\n");
			g_error_free(err);
		}
	}
	else if (active_item == 7) {
			memset(&array,0x00,sizeof(array));
			//g_file_get_contents("/root/eclipse-workspace/vision_app_gui/Debug/log2.txt", &array,&length, NULL);
			g_file_get_contents("/home/pi/Desktop/Data/87887d23b148467fb20bec81a16b5e75/logs/gps.log", &array,&length, NULL);

			utf8 = g_convert(array, length, "UTF-8", "us-ascii", bytes_read,bytes_written, &err);
			if (err != NULL) {
				printf("G_CONVERT(!NULL) error -->\n");
				g_error_free(err);
			}
	}
	gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(widgets->debuglog_buff),&start);
	gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(widgets->debuglog_buff), &end);
	gtk_text_buffer_delete(GTK_TEXT_BUFFER(widgets->debuglog_buff), &start,&end);

	gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(widgets->debuglog_buff),&iter, 0);
	gtk_text_buffer_insert(GTK_TEXT_BUFFER(widgets->debuglog_buff), &iter, utf8,-1);
#if 0
	widgets->debuglog_buff = gtk_text_view_get_buffer(GTK_TEXT_VIEW(widgets->w_debug_log_view));
	//gtk_text_buffer_set_text(GTK_TEXT_BUFFER(widgets->debuglog_buff),"hello worldgeethavanikjdsklalsllkjhja",-1);
	gtk_text_buffer_set_text(GTK_TEXT_BUFFER(widgets->debuglog_buff),logfile,-1);
#endif
	gtk_window_present(GTK_WINDOW(widgets->w_debug));
	gtk_widget_show(widgets->w_debug_log_view);
	gtk_widget_hide(widgets->w_home);
}

G_MODULE_EXPORT
void on_w_debug_text_find_clicked(GtkButton *button, app_widgets *widgets){
	GtkTextIter iter ;
	GtkTextIter mstart , mend ;
	gboolean found ;

	const char *srch;
	srch = gtk_entry_get_text(GTK_ENTRY(widgets->w_debug_search_entry));

	// Search from the start from buffer for text .
	gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(widgets->debuglog_buff), &iter) ;
	found = gtk_text_iter_forward_search(&iter , srch, 0 ,&mstart , &mend , NULL ) ;
	if ( found ) {
	//∗ If found , hilight the text .
	gtk_text_buffer_select_range (GTK_TEXT_BUFFER(widgets->debuglog_buff) , &mstart , &mend ) ;
	}

}
G_MODULE_EXPORT
//void on_w_debug_fkey4_back_clicked(GtkButton *button, app_widgets *widgets) {
void on_w_debug_fkey4_back_clicked() {
	gtk_window_present(GTK_WINDOW(widgets->w_home));
	//video_streaming_live();
	gtk_widget_hide(widgets->w_debug);
	gtk_entry_set_text(GTK_ENTRY(widgets->w_debug_search_entry),"");
	//gtk_text_view_reset_im_context(GTK_TEXT_VIEW(widgets->w_debug_log_view));
}
void video_streaming_live(GtkWidget *drawing_area) {
	inst = libvlc_new(0, NULL);
	const char * const vlc_args[] = { "--no-xlib" };
	inst = libvlc_new(0, vlc_args);

	//m = libvlc_media_new_location (inst, "rtsp://192.168.2.88:554/stander/livestream/0/1");/*ip cam*/
	//m = libvlc_media_new_location (inst, "rtsp://192.168.2.88:554/h264");/*ip cam*/
	m = libvlc_media_new_location (inst, "rtsp://admin:einsite123@192.168.255.88:554/Streaming/Channels/102/?transportmode=unicast");/*ip cam*/
	//m = libvlc_media_new_location(inst, "v4l2:///dev/video0");/*Internal cam*/
	mp = libvlc_media_player_new_from_media(m);
	libvlc_media_release(m);
	GdkWindow *draw = gtk_widget_get_window(GTK_WIDGET(drawing_area));
	unsigned int drawable = gdk_x11_window_get_xid(draw);
	libvlc_media_player_set_xwindow(mp, drawable);
	libvlc_media_player_play(mp);
}
void vlc_player_exit(void) {
	libvlc_media_player_stop(mp);
	libvlc_media_player_release(mp);
	libvlc_release(inst);
}
//////////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
//void on_w_home_key_clicked(GtkButton *button, app_widgets *widgets){
void on_w_home_key_clicked(){

	gtk_window_present(GTK_WINDOW(widgets->w_config_set));
	gtk_widget_hide(widgets->w_home);
}
//////////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
void on_w_VideoWriter_toggled(GtkToggleButton *togglebutton,app_widgets *widgets){
	g_print("toggle button selected");
}
////////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
void on_w_config_fkey_select_clicked(){
	g_print("select button pressed\n");
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widgets->w_VideoWriter))) {
		gtk_window_present(GTK_WINDOW(widgets->w_videoWriter_para));
		gtk_widget_hide(widgets->w_config_set);
		g_print("Toggled 1\n");
	} else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widgets->w_FrameDecoder_para))) {
		gtk_window_present(GTK_WINDOW(widgets->w_FrameDecoder));
		gtk_widget_hide(widgets->w_config_set);
		g_print("Toggled 2\n");
	} else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widgets->w_GpsParams_sele))) {
		gtk_window_present(GTK_WINDOW(widgets->w_GpsParams));
		gtk_widget_hide(widgets->w_config_set);
		g_print("Toggled 3\n");
	}else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widgets->w_DeciceMonitor_sel))) {
		gtk_window_present(GTK_WINDOW(widgets->w_Device_monitor));
		gtk_widget_hide(widgets->w_config_set);
		g_print("Toggled 4\n");
	}else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widgets->w_mqtt_comm_sel))) {
		gtk_window_present(GTK_WINDOW(widgets->w_mqtt_param));
		gtk_widget_hide(widgets->w_config_set);
		g_print("Toggled 5\n");
	}else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widgets->w_http_comm_sel))) {
		gtk_window_present(GTK_WINDOW(widgets->w_http_comm_param));
		gtk_widget_hide(widgets->w_config_set);
		g_print("Toggled 6\n");
	}else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widgets->w_video_image_packet_threshold_sel))) {
		gtk_window_present(GTK_WINDOW(widgets->w_video_image_packet_thresholds));
		gtk_widget_hide(widgets->w_config_set);
		g_print("Toggled 6\n");
	}


}
///////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
void on_w_model_config_fkey_select_clicked(){
	g_print("select button pressed\n");
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widgets->w_frontloader))) {
		gtk_window_present(GTK_WINDOW(widgets->w_fontloder_param));
		gtk_widget_hide(widgets->w_model_config_set);
		g_print("Toggled 1\n");
	} //else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widgets->w_FrameDecoder_para))) {
		//gtk_window_present(GTK_WINDOW(widgets->w_FrameDecoder));
		//gtk_widget_hide(widgets->w_config_set);
		//g_print("Toggled 2\n");
	//}
}
///////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
void on_w_frontloder_fkey_select2_clicked(){
	g_print("select button pressed\n");
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widgets->w_MA_sel))) {
		gtk_window_present(GTK_WINDOW(widgets->w_ma_param));
		gtk_widget_hide(widgets->w_fontloder_param);
		g_print("Toggled 1\n");
	} else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widgets->w_mo_para_sele1))) {
		gtk_window_present(GTK_WINDOW(widgets->w_mo_param));
		gtk_widget_hide(widgets->w_fontloder_param);
		g_print("Toggled 2\n");
	}

	else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widgets->w_keypoint_para_sel))) {
		gtk_window_present(GTK_WINDOW(widgets->w_keypoint_param));
		gtk_widget_hide(widgets->w_fontloder_param);
		g_print("Toggled 2\n");
	}else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widgets->w_frnotloder_bbox_sel))) {
		gtk_window_present(GTK_WINDOW(widgets->w_bbox_para_sel));
		gtk_widget_hide(widgets->w_fontloder_param);
		g_print("Toggled 2\n");
	}

}
/////////////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
void on_w_bbox_params_fkey_select_clicked(){
	g_print("select button pressed\n");
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widgets->w_bboxbucket))) {
		gtk_window_present(GTK_WINDOW(widgets->w_bbox_param));
		gtk_widget_hide(widgets->w_bbox_para_sel);
		g_print("Toggled 1\n");
	} else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widgets->w_bbox_truck))) {
		gtk_window_present(GTK_WINDOW(widgets->w_bbox_truck_param));
		gtk_widget_hide(widgets->w_bbox_para_sel);
		g_print("Toggled 2\n");
	}
}

/////////////////////////////////////////////////////////////////////////////////////////


G_MODULE_EXPORT
void on_w_videowriter_fkey4_back_clicked(){
	g_print("back button pressed\n");
	gtk_window_present(GTK_WINDOW(widgets->w_config_set));
	gtk_widget_hide(widgets->w_videoWriter_para);

}
///////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
void on_w_framedecoder_fkey4_back_clicked(){
	g_print("back button pressed\n");
	gtk_window_present(GTK_WINDOW(widgets->w_config_set));
	gtk_widget_hide(widgets->w_FrameDecoder);
}
/////////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
void on_w_gps_params_fkey4_back_clicked(){
	g_print("back button pressed\n");
	gtk_window_present(GTK_WINDOW(widgets->w_config_set));
	gtk_widget_hide(widgets->w_GpsParams);
}
////////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
void on_w_config_set_fkey4_back_clicked(){
	g_print("back button pressed\n");
	gtk_window_present(GTK_WINDOW(widgets->w_config_set));
	gtk_widget_hide(widgets->w_config_set);
}
///////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
void on_w_DeviceMonitor_fkey4_back_clicked(){
	gtk_window_present(GTK_WINDOW(widgets->w_config_set));
	gtk_widget_hide(widgets->w_Device_monitor);
}
//////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
void on_w_mqtt_comm_fkey4_back_clicked(){
	gtk_window_present(GTK_WINDOW(widgets->w_config_set));
	gtk_widget_hide(widgets->w_mqtt_param);
}
//////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
void on_w_http_comm_fkey4_back_clicked(){
	gtk_window_present(GTK_WINDOW(widgets->w_config_set));
	gtk_widget_hide(widgets->w_http_comm_param);
}
//////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
void on_w_video_imge_threshold_fkey4_back_clicked(){
	gtk_window_present(GTK_WINDOW(widgets->w_config_set));
	gtk_widget_hide(widgets->w_video_image_packet_thresholds);
}
//////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
void on_w_home_fkey3_clicked(){
	gtk_window_present(GTK_WINDOW(widgets->w_model_config_set));
	gtk_widget_hide(widgets->w_home);
}
//////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
void on_w_model_config_set_fkey4_back_clicked(){
	gtk_window_present(GTK_WINDOW(widgets->w_home));
	gtk_widget_hide(widgets->w_model_config_set);
}
//////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
void on_w_model_config_set_fkey4_back5_clicked(){
	gtk_window_present(GTK_WINDOW(widgets->w_model_config_set));
	gtk_widget_hide(widgets->w_fontloder_param);
}
//////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
void on_w_ma_params_fkey4_back3_clicked(){
	gtk_window_present(GTK_WINDOW(widgets->w_fontloder_param));
	gtk_widget_hide(widgets->w_ma_param);

}
////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
void on_w_keypoint_fkey4_back_clicked(){
	gtk_window_present(GTK_WINDOW(widgets->w_fontloder_param));
	gtk_widget_hide(widgets->w_keypoint_param);
}
//////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
void on_w_mo_param_next_fkey3_clicked(){
	gtk_window_present(GTK_WINDOW(widgets->w_mo_param_contu));
	gtk_widget_hide(widgets->w_mo_param);
}
//////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
void on_w_mo_para_contu_fkey4_back1_clicked(){
	gtk_window_present(GTK_WINDOW(widgets->w_mo_param));
	gtk_widget_hide(widgets->w_mo_param_contu);
}
//////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
void on_w_mo_params_fkey4_back_clicked(){
	gtk_window_present(GTK_WINDOW(widgets->w_fontloder_param));
	gtk_widget_hide(widgets->w_mo_param);
}
//////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
void on_w_bbox_param_next_fkey1_clicked(){
	gtk_window_present(GTK_WINDOW(widgets->w_bbox_bucket_contu_param1));
	gtk_widget_hide(widgets->w_bbox_param);
}
///////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
void on_w_bbox_params_fkey4_back2_clicked(){
	gtk_window_present(GTK_WINDOW(widgets->w_bbox_param));
	gtk_widget_hide(widgets->w_bbox_bucket_contu_param1);
}
////////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
void on_w_bbox_params_fkey4_back1_clicked(){
	gtk_window_present(GTK_WINDOW(widgets->w_fontloder_param));
	gtk_widget_hide(widgets->w_bbox_param);
}
///////////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
void on_w_bbox_truck_param_next_fkey3_clicked(){
	gtk_window_present(GTK_WINDOW(widgets->w_bbox_truck_countu_param));
	gtk_widget_hide(widgets->w_bbox_truck_param);
}
////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
void on_w_bbox_tuck_params_fkey4_back_clicked(){
	gtk_window_present(GTK_WINDOW(widgets->w_bbox_para_sel));
	gtk_widget_hide(widgets->w_bbox_truck_param);
}
///////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
void on_w_bbox_tuck_contu_params_fkey4_back1_clicked(){
	gtk_window_present(GTK_WINDOW(widgets->w_bbox_truck_param));
	gtk_widget_hide(widgets->w_bbox_truck_countu_param);
}
///////////////////////////////////////////////////////////////////////////////////
G_MODULE_EXPORT
void on_w_bbox_params_fkey4_back_clicked(){
	gtk_window_present(GTK_WINDOW(widgets->w_fontloder_param));
	gtk_widget_hide(widgets->w_bbox_para_sel);
}
////////////////////////////////////////////////////////////////////////////////////

//int main(void) {
int main_glade_thread(){
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	GtkBuilder *builder;
	GtkWidget *window;

	gtk_init(0, 0);
	widgets = g_slice_new(app_widgets);
	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "./w_main_vision.glade", NULL);
	window = GTK_WIDGET(gtk_builder_get_object(builder, "w_home"));
	widgets->w_debug = GTK_WIDGET(gtk_builder_get_object(builder, "w_Debug"));
	widgets->w_logfile_sel = GTK_WIDGET(gtk_builder_get_object(builder, "w_logfile_sel"));
	widgets->w_config_set = GTK_WIDGET(gtk_builder_get_object(builder, "w_config_set"));
	widgets->w_videoWriter_para = GTK_WIDGET(gtk_builder_get_object(builder, "w_videoWriter_para"));
	widgets->w_FrameDecoder_para = GTK_WIDGET(gtk_builder_get_object(builder, "w_FrameDecoder_para"));
	widgets->w_DeciceMonitor_sel = GTK_WIDGET(gtk_builder_get_object(builder, "w_DeciceMonitor_sel"));
	widgets->w_Device_monitor = GTK_WIDGET(gtk_builder_get_object(builder, "w_DeviceMonitor"));
	widgets->w_mqtt_param = GTK_WIDGET(gtk_builder_get_object(builder, "w_mqtt_param"));
	widgets->w_mqtt_comm_sel = GTK_WIDGET(gtk_builder_get_object(builder, "w_mqtt_comm_sel"));
	widgets->w_http_comm_param = GTK_WIDGET(gtk_builder_get_object(builder, "w_http_comm_param"));
	widgets->w_http_comm_sel = GTK_WIDGET(gtk_builder_get_object(builder, "w_http_comm_sel"));
	widgets->w_video_image_packet_thresholds = GTK_WIDGET(gtk_builder_get_object(builder, "w_video_image_packet_thresholds"));
	widgets->w_video_image_packet_threshold_sel = GTK_WIDGET(gtk_builder_get_object(builder, "w_video_image_packet_threshold_sel"));
	widgets->w_model_config_set = GTK_WIDGET(gtk_builder_get_object(builder, "w_model_config_set"));

	widgets->w_fontloder_param = GTK_WIDGET(gtk_builder_get_object(builder, "w_fontloder_param"));
	widgets->w_frontloader = GTK_WIDGET(gtk_builder_get_object(builder, "w_frontloader"));
	widgets->w_MA_sel = GTK_WIDGET(gtk_builder_get_object(builder, "w_MA_sel"));
	widgets->w_ma_param = GTK_WIDGET(gtk_builder_get_object(builder, "w_ma_param"));
	widgets->w_keypoint_param = GTK_WIDGET(gtk_builder_get_object(builder, "w_keypoint_param"));
	widgets->w_keypoint_para_sel = GTK_WIDGET(gtk_builder_get_object(builder, "w_keypoint_para_sel"));

	widgets->w_mo_para_sele1 = GTK_WIDGET(gtk_builder_get_object(builder, "w_mo_para_sele1"));
	widgets->w_mo_param = GTK_WIDGET(gtk_builder_get_object(builder, "w_mo_param"));
	widgets->w_mo_param_contu = GTK_WIDGET(gtk_builder_get_object(builder, "w_mo_param_contu"));
	widgets->w_frnotloder_bbox_sel = GTK_WIDGET(gtk_builder_get_object(builder, "w_frnotloder_bbox_sel"));
	widgets->w_bbox_para_sel = GTK_WIDGET(gtk_builder_get_object(builder, "w_bbox_para_sel"));


	widgets->w_bboxbucket = GTK_WIDGET(gtk_builder_get_object(builder, "w_bboxbucket"));
	widgets->w_bbox_truck = GTK_WIDGET(gtk_builder_get_object(builder, "w_bbox_truck"));
	widgets->w_bbox_param = GTK_WIDGET(gtk_builder_get_object(builder, "w_bbox_param"));
	widgets->w_bbox_bucket_contu_param1 = GTK_WIDGET(gtk_builder_get_object(builder, "w_bbox_bucket_contu_param1"));
	widgets->w_bbox_truck_param = GTK_WIDGET(gtk_builder_get_object(builder, "w_bbox_truck_param"));
	widgets->w_bbox_truck_countu_param = GTK_WIDGET(gtk_builder_get_object(builder, "w_bbox_truck_countu_param"));


	//w_GpsParams
	widgets->w_VideoWriter = GTK_WIDGET(gtk_builder_get_object(builder, "w_VideoWriter"));
	widgets->w_FrameDecoder = GTK_WIDGET(gtk_builder_get_object(builder, "w_FrameDecoder"));
	widgets->w_GpsParams_sele = GTK_WIDGET(gtk_builder_get_object(builder, "w_GpsParams_sele"));
	widgets->w_GpsParams = GTK_WIDGET(gtk_builder_get_object(builder, "w_GpsParam"));

	/*video stream widgets*/
	widgets->w_lgn_cam = GTK_WIDGET(gtk_builder_get_object(builder, "w_lgn_cam"));
	widgets->w_debug_log_view = GTK_WIDGET(gtk_builder_get_object(builder, "w_debug_log_view"));
	widgets->debuglog_buff = GTK_WIDGET(gtk_builder_get_object(builder, "debuglog_buff"));
	widgets->w_debug_search_entry = GTK_WIDGET(gtk_builder_get_object(builder, "w_debug_search_entry"));
	gtk_builder_connect_signals(builder, widgets);
	gtk_widget_show(window);
	gtk_widget_show(widgets->w_lgn_cam);
	video_streaming_live(widgets->w_lgn_cam);
	g_object_unref(builder);
	gtk_main();

	return EXIT_SUCCESS;
}
int thread2_main() {

	struct json_object * json_policy_array;
	setenv("/home/geetha/Desktop/vision_app_gui/Debug/", ".", 1);
	Py_Initialize();
	PySys_SetPath(".");
	PyObject *name = PyUnicode_FromString("py_globle_va_read");
	if (!name) {
		PyErr_Print();
		printf("Error formating python script\n");
	}
	PyObject *mod = PyImport_Import(name);
	if (!mod) {
		PyErr_Print();
		printf("Error importing python script\n");
	}
	while (1) {
		sleep(5);
		PyObject *var1Py = PyObject_GetAttrString(mod, "update");
		int  var1Int = PyLong_AsLong(var1Py);
		printf("update %d", var1Int);
		if (var1Int == 1) {
			if (mod) {
				PyObject *pFunc = PyObject_GetAttrString(mod, "getInteger");
				if (pFunc && PyCallable_Check(pFunc)) {
					PyObject *pValue = PyObject_CallObject(pFunc, NULL);
					printf("C: getInteger() = %ld\n", PyLong_AsLong(pValue));
					json_policy_array = json_object_from_file("/home/geetha/Geetha_work/models.json");
					printf("%s\n",json_object_to_json_string(json_policy_array));

				} else {
					printf("ERROR: function getInteger()\n");
				}

			} else {
				printf("ERROR: Module not imported\n");
			}
		} else {
			printf("not updated\n");
		}
	}


	return 0;
}

int main(int argc, char* argv[]) {
	//main_glade_thread();
	printf("--------");

	pthread_attr_t attr;
	int status;
	//signal(SIGINT, sig_handler);
	//counter = 0;
	//load_the_device_config();
	pthread_attr_init(&attr);
	pthread_attr_setstacksize(&attr, 1024 * 1024);

	printf("Creating thread1\n");
	status = pthread_create(&thread1, &attr, (void*) &main_glade_thread, NULL);

	if (status != 0) {
		printf("Failed to create thread1 with status = %d\n", status);

	}

	printf("Creating thread2\n");
	status = pthread_create(&thread2, &attr, (void*) &thread2_main, NULL);
	if (status != 0) {
		printf("Failed to create thread2 with status = %d\n", status);
		//ASSERT(status == 0);
	}

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	//sig_handler(SIGINT);
//   return 0;
}

