/**
 * Copyright (C) 2011-2012 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * "Frost And Flame" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Frost And Flame" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.co.nr
 * @license GPL V3
 * @date 2011-11-11
 */

#ifndef MENU_H
#define MENU_H

#include <string>

#define NORMAL   0
#define CLOSE    1
#define SLIDER   2
#define TOGGLE   3
#define CHOICE   4
#define ACHIEVE  5

const int MAX_MENU_BUTTONS        = 12;
const int MAX_MENU_CHOICE_BUTTONS = 32;

//-------------------------- button -------------------------------
class button_class
{
    private:
    public:
        struct choice_data_type
        {
            bool         active;
            bool         enabled;
            int          image_ref;
            std::string  text_label;
            bool         highlighted;
            float        zoom_size_counter;
        };
        choice_data_type choice_data[MAX_MENU_CHOICE_BUTTONS];
        int              number_of_choices;
        int              number_of_visible_choices;
        int              current_choice;
        int              type;
        bool             active;
        int              image_normal;
        int              image_highlighted;
        int              image_disabled;
        int              image_choice_disabled;
        int              image_selector;
        int              image_slider_normal;
        int              image_slider_highlighted;
        int              image_arrow_normal;
        int              image_arrow_highlighted;
        int              image_arrow_disabled;
        int              image_toggle_true_highlighted;
        int              image_toggle_true_normal;
        int              image_toggle_false_highlighted;
        int              image_toggle_false_normal;
        int              image_achieve_highlighted;
        int              image_achieve_normal;
        bool             highlighted;
        bool             arrow_left_highlighted;
        bool             arrow_right_highlighted;
        bool             enabled;
        bool             glow;
        bool             zoom;
        float            zoom_size;
        float            zoom_size_counter;
        float            zoom_speed;
        float            pos_x;
        float            pos_y;
        float            pos_z;
        float            height;
        float            width;
        float            arrow_left_zoom_size_counter;
        float            arrow_right_zoom_size_counter;
        float            arrow_left_pos_x;
        float            arrow_left_pos_y;
        float            arrow_right_pos_x;
        float            arrow_right_pos_y;
        float            arrow_width;
        float            arrow_height;
        int              slider_position;
        int              slider_position_max;
        float            slider_pos_x;
        float            slider_pos_y;
        float            slider_width;
        float            slider_height;
        int              choice_position;
        std::string      label;
        std::string      disabled_text_label;
        int              button_font;
        int              normal_color_r;
        int              normal_color_g;
        int              normal_color_b;
        int              normal_color_a;
        int              highlighted_color_r;
        int              highlighted_color_g;
        int              highlighted_color_b;
        int              highlighted_color_a;
        int              disabled_color_r;
        int              disabled_color_g;
        int              disabled_color_b;
        int              disabled_color_a;
        bool             toggle_data;
        int              achieve_data;
        int              achieve_position;
        float            text_width;
        float            text_height;
        button_class(void);
        button_class(float x, float y, float z, float w, float h, int in, int ih, int id, bool hl, bool en, bool gl, bool zm, float zs, int nr, int ng, int nb, int na, int hr, int hg, int hb, int ha, int dr, int dg, int db, int da, std::string lb);
       ~button_class(void);
        void  set_pos(float x, float y, float z);
        void  set_pos_x(float x);
        void  set_pos_y(float y);
        void  set_pos_z(float z);
        float get_pos_x(void);
        float get_pos_y(void);
        float get_pos_z(void);
        void  set_size(float w, float h);
        float get_width(void);
        float get_height(void);
        void  set_label(std::string text);
        void  set_disabled_text_label(std::string disabled_text_label);
        void  set_color_normal(int r, int g, int b, int a);
        void  set_color_highlighted(int r, int g, int b, int a);
        void  set_color_disabled(int r, int g, int b, int a);
        void  draw(void);
        void  set_image_normal(int image);
        void  set_image_disabled(int image);
        void  set_image_highlighted(int image);
        void  set_image_choice_disabled(int image);
        void  set_image_selector(int image);
        void  set_image_slider_normal(int image);
        void  set_image_slider_highlighted(int image);
        void  set_image_arrow_normal(int image);
        void  set_image_arrow_disabled(int image);
        void  set_image_arrow_highlighted(int image);
        void  set_image_toggle_true_highlighted(int image);
        void  set_image_toggle_true_normal(int image);
        void  set_image_toggle_false_highlighted(int image);
        void  set_image_toggle_false_normal(int image);
        void  set_enabled(bool bool_value);
        bool  get_enabled(void);
        void  set_highlighted(bool bool_value);
        bool  get_highlighted(void);
        bool  mouse_over(void);
        bool  mouse_clicked(void);
        bool  button_pressed(void);
        void  set_active(bool bool_data);
        bool  get_active(void);
        void  set_zoom(bool bool_data);
        void  set_zoom(bool bool_data, float zs);
        void  set_zoom(bool bool_data, float zs, float zsp);
        void  set_font(int font_number);
        int   get_font(void);
        void  set_zoom_size(float zs);
        float get_zoom_size(void);
        void  set_zoom_size_counter(float zsc);
        float get_zoom_size_counter(void);
        void  set_zoom_speed(float zsp);
        float get_zoom_speed(void);
        void  set_data(float x, float y, float z, float w, float h, int in, int ih);
        void  set_data(float x, float y, float z, float w, float h);
        void  set_data(int in, int ih);
        void  set_button_type(int bt);
        int   get_button_type(void);
        void  set_arrow_left_pos_x(float set_data);
        float get_arrow_left_pos_x(void);
        void  set_arrow_left_pos_y(float set_data);
        float get_arrow_left_pos_y(void);
        void  set_arrow_right_pos_x(float set_data);
        float get_arrow_right_pos_x(void);
        void  set_arrow_right_pos_y(float set_data);
        float get_arrow_right_pos_y(void);
        void  set_arrow_width(float set_data);
        float get_arrow_width(void);
        void  set_arrow_height(float set_data);
        float get_arrow_height(void);
        void  set_arrow_data(float lx, float ly, float rx, float ry, float w, float h);
        void  set_slider_position(int set_data);
        int   get_slider_position(void);
        void  set_slider_position_max(int set_data);
        int   get_slider_position_max(void);
        void  set_choice_position(int set_data);
        int   get_choice_position(void);
        void  set_choice_data(int choice_number, int image_ref_data, std::string text_label_data, bool active_data);
        void  set_choice_data(int choice_number, int image_ref_data, bool active_data);
        void  set_number_of_choices(int choice_data);
        int   get_number_of_choices(void);
        void  set_number_of_visible_choices(int visible_choice_data);
        int   get_number_of_visible_choices(void);
        void  set_choice_enabled(int choice_number, bool enabled_data);
        bool  get_choice_enabled(int choice_number);
        void  set_choice_zoom_size_counter(int choice_number, float zoom_data);
        float get_choice_zoom_size_counter(int choice_number);
        void  set_arrow_left_zoom_size_counter(float zoom_data);
        float get_arrow_left_zoom_size_counter(void);
        void  set_arrow_right_zoom_size_counter(float zoom_data);
        float get_arrow_right_zoom_size_counter(void);
        void  set_choice_highlighted(int choice_number, bool bool_data);
        bool  get_choice_highlighted(int choice_number);
        void  set_arrow_left_highlighted (bool bool_data);
        bool  get_arrow_left_highlighted (void);
        void  set_arrow_right_highlighted(bool bool_data);
        bool  get_arrow_right_highlighted(void);
        void  set_slider_pos_x(float float_data);
        float get_slider_pos_x(void);
        void  set_slider_pos_y(float float_data);
        float get_slider_pos_y(void);
        void  set_slider_width(float float_data);
        float get_slider_width(void);
        void  set_slider_height(float float_data);
        float get_slider_height(void);
        void  set_current_choice(int choice_data);
        int   get_current_choice(void);
        void  set_toggle_data(bool bool_data);
        bool  get_toggle_data(void);
        void  set_toggle_images(int tth, int ttn, int tfh, int tfn);
        void  set_image_achieve_highlighted(int image);
        void  set_image_achieve_normal(int image);
        void  set_achieve_data(int int_data);
        int   get_achieve_data(void);
        void  set_achieve_position(int int_data);
        void  set_text_size(float width, float height);
};

//-------------------------- menu -------------------------------
class menu_class
{
    private:
    public:
        bool          drag_active;
        float         drag_offset_x;
        float         drag_offset_y;
        int           keyboard_delay;
        int           keyboard_delay_count;
        int           mouse_delay;
        int           mouse_delay_count;
        int           current_vertical_selection;
        int           current_horizontal_selection;
        int           number_of_buttons;
        float         pos_x;
        float         pos_y;
        float         pos_z;
        int           image_background;
        int           button_image_normal;
        int           button_image_highlighted;
        int           button_image_disabled;
        int           button_image_choice_disabled;
        int           button_image_selector;
        int           button_image_slider_normal;
        int           button_image_slider_highlighted;
        int           button_image_arrow_normal;
        int           button_image_arrow_highlighted;
        int           button_image_arrow_disabled;
        int           button_image_toggle_true_highlighted;
        int           button_image_toggle_true_normal;
        int           button_image_toggle_false_highlighted;
        int           button_image_toggle_false_normal;
        int           button_image_achieve_highlighted;
        int           button_image_achieve_normal;
        float         button_width;
        float         button_height;
        float         button_spacing;
        float         button_x_pos;
        float         button_y_pos;
        float         button_z_pos;
        float         button_arrow_left_pos_x;
        float         button_arrow_left_pos_y;
        float         button_arrow_right_pos_x;
        float         button_arrow_right_pos_y;
        float         button_arrow_width;
        float         button_arrow_height;
        float         button_slider_position;
        bool          enabled;
        bool          glow;
        bool          zoom;
        float         zoom_size;
        float         zoom_size_counter;
        float         zoom_speed;
        float         height;
        float         width;
        std::string   title_label;
        std::string   button_disabled_text_label;
        float         title_height;
        float         title_width;
        float         title_pos_x;
        float         title_pos_y;
        float         title_pos_z;
        int           menu_font;
        int           button_font;
        int           title_color_r;
        int           title_color_g;
        int           title_color_b;
        int           title_color_a;
        int           normal_color_r;
        int           normal_color_g;
        int           normal_color_b;
        int           normal_color_a;
        int           highlighted_color_r;
        int           highlighted_color_g;
        int           highlighted_color_b;
        int           highlighted_color_a;
        int           disabled_color_r;
        int           disabled_color_g;
        int           disabled_color_b;
        int           disabled_color_a;
        float         text_width;
        float         text_height;
        button_class  close_button;
        button_class  button[MAX_MENU_BUTTONS];
        menu_class(void);
        menu_class(int num_buttons);
        void  draw(void);
        void  set_pos(float x, float y, float z);
        void  set_size(float w, float h);
        void  set_image_background(int bi);
        void  set_color_title(int r, int g, int b, int a);
        void  set_color_normal(int r, int g, int b, int a);
        void  set_color_highlighted(int r, int g, int b, int a);
        void  set_color_disabled(int r, int g, int b, int a);
        void  set_button_image_normal(int image);
        void  set_button_image_disabled(int image);
        void  set_button_image_highlighted(int image);
        void  set_button_zoom(bool z, float zs);
        void  set_button_zoom(bool bool_data, float zs, float zsp);
        void  set_button_data(int button_number);
        void  set_button_data(int button_number, std::string label);
        void  set_button_data(int button_number, std::string label,float x, float y, float z);
        void  set_button_disabled_text_label(std::string disabled_text_label);
        void  set_button_data(void);
        void  set_button_size(float w, float h);
        void  set_number_of_buttons(int nob);
        void  set_button_active(int button_number, bool bool_data);
        void  set_button_spacing(void);
        void  set_button_spacing(float button_offset);
        void  set_button_spacing_auto(void);
        void  set_button_spacing_auto(float button_offset);
        void  set_button_x_pos(float xp);
        float get_button_x_pos(int button_number);
        float get_button_y_pos(int button_number);
        float get_menu_x_pos(void);
        void  set_button_y_pos(float yp);
        float get_menu_y_pos(void);
        void  set_button_z_pos(float zp);
        float get_menu_z_pos(void);
        void  set_menu_title(std::string menu_title);
        void  set_menu_font(int font_number);
        void  set_menu_button_font(int font_number);
        void  set_button_font(int button_number);
        int   get_menu_font(void);
        void  set_button_size_auto(void);
        void  set_current_vertical_selection(int cvs);
        int   get_current_vertical_selection(void);
        bool  mouse_over_any_button(void);
        void  set_zoom_size_counter(int button_number,float zsc);
        float get_zoom_size_counter(int button_number);
        void  set_zoom_speed(int button_number,float zsp);
        float get_zoom_speed(int button_number);
        void  set_close_button_data(float x, float y, float z, float w, float h, int in, int ih);
        void  set_close_button_data(float x, float y, float z, float w, float h);
        void  set_close_button_data(float x, float y, float z);
        void  set_close_button_data(int in, int ih);
        float get_close_button_pos_x(void);
        float get_close_button_pos_y(void);
        float get_close_button_pos_z(void);
        void  set_close_button_type(int bt);
        void  set_keyboard_delay(int kd);
        int   get_keyboard_delay(void);
        void  set_keyboard_delay_count(int kdc);
        int   get_keyboard_delay_count(void);
        void  set_mouse_delay(int md);
        int   get_mouse_delay(void);
        void  set_mouse_delay_count(int mdc);
        int   get_mouse_delay_count(void);
        void  set_drag_active(bool bool_data);
        bool  get_drag_active(void);
        void  set_title_data(std::string menu_title);
        void  set_title_data(float x, float y, float z, float w, float h, std::string menu_title);
        bool  mouse_over_title(void);
        bool  mouse_click_title(void);
        float set_buttons_auto(void);
        void  set_image_arrow_normal(int image_ref_no);
        void  set_image_arrow_highlighted(int image_ref_no);
        void  set_image_arrow_disabled(int image_ref_no);
        void  set_button_images(int in, int ih, int id, int icd, int is, int isn, int ish, int ian, int iah, int iad);
        void  set_button_arrow_left_pos_x (float set_data);
        void  set_button_arrow_left_pos_y (float set_data);
        void  set_button_arrow_right_pos_x(float set_data);
        void  set_button_arrow_right_pos_y(float set_data);
        void  set_button_arrow_width(float set_data);
        void  set_button_arrow_height(float set_data);
        void  set_button_arrow_data(int button_number, float lx, float ly, float rx, float ry, float w, float h);
        void  set_button_arrow_data_auto(int button_number);
        void  set_button_slider_position(int button_number, float set_data);
        float get_button_slider_position(int button_number);
        void  set_button_slider_position_max(int button_number, float set_data);
        float get_button_slider_position_max(int button_number);
        void  set_button_choice_position(int button_number, int set_data);
        int   get_button_choice_position(int button_number);
        void  set_button_current_choice(int button_number, int choice_data);
        int   get_button_current_choice(int button_number);
        void  set_button_choice_data(int button_number, int choice_number, int image_ref_data, std::string text_label_data, bool active_data, bool enabled_data);
        void  set_button_choice_data(int button_number, int choice_number, int image_ref_data, bool active_data, bool enabled_data);
        void  set_number_of_choices(int button_number, int choice_data);
        int   get_number_of_choices(int button_number);
        void  set_number_of_visible_choices(int button_number, int visible_choice_data);
        int   get_number_of_visible_choices(int button_number);
        void  set_button_type(int button_number, int bt);
        int   get_button_type(int button_number);
        void  set_button_choice_enabled(int button_number, int choice_number, bool enabled_data);
        bool  get_button_choice_enabled(int button_number, int choice_number);
        int   mouse_over_button_choice(int button_number);
        int   mouse_click_button_choice(int button_number);
        void  set_button_slider_data(int button_number, int position_data, std::string text_label_data, bool active_data, bool enabled_data);
        int   mouse_over_button_slider(int button_number);
        int   mouse_click_button_slider(int button_number);
        void  set_toggle_data(int button_number, bool bool_data);
        bool  get_toggle_data(int button_number);
        void  set_toggle_button_images(int tth, int ttn, int tfh, int tfn);
        void  set_achieve_data(int button_number, int int_data);
        int   get_achieve_data(int button_number);
        void  set_achieve_button_images(int ah, int an);
        void  set_achieve_position(int button_number, int int_data);
        bool  get_button_enabled(int button_number);
        void  set_button_enabled(int button_number, bool bool_data);
        void  set_text_size(float width, float height);
        int   process(void);
};

#endif //MENU_H







































