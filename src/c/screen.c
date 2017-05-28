#include <pebble.h>
#include "screen.h"

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GFont s_res_font_test_10;
static GFont s_res_gothic_24_bold;
static GFont s_res_gothic_14;
static BitmapLayer *s_bitmaplayer_1;
static TextLayer *s_textlayer_1;
static BitmapLayer *s_bitmaplayer_2;
static TextLayer *s_textlayer_2;
static TextLayer *s_textlayer_3;
static TextLayer *s_textlayer_4;
static BitmapLayer *s_bitmaplayer_3;
static BitmapLayer *s_bitmaplayer_4;

static void initialise_ui(void) {
  s_window = window_create();
  #ifndef PBL_SDK_3
    window_set_fullscreen(s_window, true);
  #endif
  
  s_res_font_test_10 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_TEST_10));
  s_res_gothic_24_bold = fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD);
  s_res_gothic_14 = fonts_get_system_font(FONT_KEY_GOTHIC_14);
  // s_bitmaplayer_1
  s_bitmaplayer_1 = bitmap_layer_create(GRect(19, 78, 64, 32));
  bitmap_layer_set_background_color(s_bitmaplayer_1, GColorBlack);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_bitmaplayer_1);
  
  // s_textlayer_1
  s_textlayer_1 = text_layer_create(GRect(9, 62, 100, 10));
  text_layer_set_text(s_textlayer_1, "in a forest...");
  text_layer_set_font(s_textlayer_1, s_res_font_test_10);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_1);
  
  // s_bitmaplayer_2
  s_bitmaplayer_2 = bitmap_layer_create(GRect(0, 0, 48, 48));
  bitmap_layer_set_background_color(s_bitmaplayer_2, GColorBlack);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_bitmaplayer_2);
  
  // s_textlayer_2
  s_textlayer_2 = text_layer_create(GRect(50, 0, 100, 24));
  text_layer_set_text(s_textlayer_2, "11:00 PM");
  text_layer_set_font(s_textlayer_2, s_res_gothic_24_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_2);
  
  // s_textlayer_3
  s_textlayer_3 = text_layer_create(GRect(50, 28, 100, 14));
  text_layer_set_text(s_textlayer_3, "Mon 24 Oct");
  text_layer_set_font(s_textlayer_3, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_3);
  
  // s_textlayer_4
  s_textlayer_4 = text_layer_create(GRect(7, 139, 144, 20));
  text_layer_set_text(s_textlayer_4, "H:13  A:3  D:2  S:0");
  text_layer_set_font(s_textlayer_4, s_res_font_test_10);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_4);
  
  // s_bitmaplayer_3
  s_bitmaplayer_3 = bitmap_layer_create(GRect(8, 154, 128, 16));
  bitmap_layer_set_background_color(s_bitmaplayer_3, GColorBlack);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_bitmaplayer_3);
  
  // s_bitmaplayer_4
  s_bitmaplayer_4 = bitmap_layer_create(GRect(53, 89, 64, 32));
  bitmap_layer_set_background_color(s_bitmaplayer_4, GColorBlack);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_bitmaplayer_4);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  bitmap_layer_destroy(s_bitmaplayer_1);
  text_layer_destroy(s_textlayer_1);
  bitmap_layer_destroy(s_bitmaplayer_2);
  text_layer_destroy(s_textlayer_2);
  text_layer_destroy(s_textlayer_3);
  text_layer_destroy(s_textlayer_4);
  bitmap_layer_destroy(s_bitmaplayer_3);
  bitmap_layer_destroy(s_bitmaplayer_4);
  fonts_unload_custom_font(s_res_font_test_10);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}



static GBitmap* s_bg[2];

void show_screen(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
  
//  text_layer_set_font(s_textlayer_2, fonts_get_system_font(FONT_KEY_LECO_28_LIGHT_NUMBERS));  
//  text_layer_set_font(s_textlayer_2, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));  

//  text_layer_set_font(s_textlayer_4, fonts_get_system_font(FONT_KEY_FONT_FALLBACK_INTERNAL) );


  static int tbl[] = {
    RESOURCE_ID_IMAGE_SCN00,
    RESOURCE_ID_IMAGE_SCN01,
    RESOURCE_ID_IMAGE_SCN02,
  };

  s_bg[0] = gbitmap_create_with_resource( tbl[rand()%3] );
  s_bg[1] = gbitmap_create_with_resource( tbl[rand()%3] );
  bitmap_layer_set_bitmap( s_bitmaplayer_1, s_bg[0] );
  bitmap_layer_set_bitmap( s_bitmaplayer_4, s_bg[1] );
}

void hide_screen(void) {
  window_stack_remove(s_window, true);

  for( int i=0; i<2; i++ ) {
    if( s_bg[i] ) gbitmap_destroy( s_bg[i] );
  }
}
