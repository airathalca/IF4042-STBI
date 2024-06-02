/*
 * smart_xmain_stubs.c - Notify and event callback function stubs.
 * This file was generated by `gxv' from `smart_xmain.G'.
 * DO NOT EDIT BY HAND.
 */

#include <stdio.h>
#include <sys/param.h>
#include <sys/types.h>
#include <xview/xview.h>
#include <xview/panel.h>
#include <xview/textsw.h>
#include <xview/xv_xrect.h>
#include <gdd.h>
#include "smart_xmain_ui.h"

#ifdef MAIN

/*
 * Instance XV_KEY_DATA key.  An instance is a set of related
 * user interface objects.  A pointer to an object's instance
 * is stored under this key in every object.  This must be a
 * global variable.
 */
Attr_attribute	INSTANCE;

void
main(argc, argv)
	int		argc;
	char		**argv;
{
	smart_xmain_basewindow_objects	*smart_xmain_basewindow;
	
	/*
	 * Initialize XView.
	 */
	xv_init(XV_INIT_ARGC_PTR_ARGV, &argc, argv, 0);
	INSTANCE = xv_unique_key();
	
	/*
	 * Initialize user interface components.
	 */
	smart_xmain_basewindow = smart_xmain_basewindow_objects_initialize(NULL, NULL);
	
	/*
	 * Turn control over to XView.
	 */
	xv_main_loop(smart_xmain_basewindow->basewindow);
	exit(0);
}

#endif

/*
 * Menu handler for `quit_menu (quit)'.
 */
Menu_item
x_quit(item, op)
	Menu_item	item;
	Menu_generate	op;
{
	smart_xmain_basewindow_objects * ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	switch (op) {
	case MENU_DISPLAY:
		break;

	case MENU_DISPLAY_DONE:
		break;

	case MENU_NOTIFY:
		fputs("smart_xmain: x_quit: MENU_NOTIFY\n", stderr);
		break;

	case MENU_NOTIFY_DONE:
		break;
	}
	return item;
}

/*
 * Menu handler for `quit_menu (xit)'.
 */
Menu_item
x_xit(item, op)
	Menu_item	item;
	Menu_generate	op;
{
	smart_xmain_basewindow_objects * ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	switch (op) {
	case MENU_DISPLAY:
		break;

	case MENU_DISPLAY_DONE:
		break;

	case MENU_NOTIFY:
		fputs("smart_xmain: x_xit: MENU_NOTIFY\n", stderr);
		break;

	case MENU_NOTIFY_DONE:
		break;
	}
	return item;
}

/*
 * Menu handler for `save_menu (Save last command)'.
 */
Menu_item
savelast_popup(item, op)
	Menu_item	item;
	Menu_generate	op;
{
	smart_xmain_basewindow_objects * ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	switch (op) {
	case MENU_DISPLAY:
		break;

	case MENU_DISPLAY_DONE:
		break;

	case MENU_NOTIFY:
		fputs("smart_xmain: savelast_popup: MENU_NOTIFY\n", stderr);
		break;

	case MENU_NOTIFY_DONE:
		break;
	}
	return item;
}

/*
 * Menu handler for `save_menu (        Save all)'.
 */
Menu_item
saveall_popup(item, op)
	Menu_item	item;
	Menu_generate	op;
{
	smart_xmain_basewindow_objects * ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	switch (op) {
	case MENU_DISPLAY:
		break;

	case MENU_DISPLAY_DONE:
		break;

	case MENU_NOTIFY:
		fputs("smart_xmain: saveall_popup: MENU_NOTIFY\n", stderr);
		break;

	case MENU_NOTIFY_DONE:
		break;
	}
	return item;
}

/*
 * Menu handler for `advanced_menu (Raw_doc)'.
 */
Menu_item
x_raw_doc(item, op)
	Menu_item	item;
	Menu_generate	op;
{
	smart_xmain_basewindow_objects * ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	switch (op) {
	case MENU_DISPLAY:
		break;

	case MENU_DISPLAY_DONE:
		break;

	case MENU_NOTIFY:
		fputs("smart_xmain: x_raw_doc: MENU_NOTIFY\n", stderr);
		break;

	case MENU_NOTIFY_DONE:
		break;
	}
	return item;
}

/*
 * Menu handler for `advanced_menu (Top_ranked)'.
 */
Menu_item
x_top_ranked(item, op)
	Menu_item	item;
	Menu_generate	op;
{
	smart_xmain_basewindow_objects * ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	switch (op) {
	case MENU_DISPLAY:
		break;

	case MENU_DISPLAY_DONE:
		break;

	case MENU_NOTIFY:
		fputs("smart_xmain: x_top_ranked: MENU_NOTIFY\n", stderr);
		break;

	case MENU_NOTIFY_DONE:
		break;
	}
	return item;
}

/*
 * Menu handler for `advanced_menu (Location)'.
 */
Menu_item
x_location(item, op)
	Menu_item	item;
	Menu_generate	op;
{
	smart_xmain_basewindow_objects * ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	switch (op) {
	case MENU_DISPLAY:
		break;

	case MENU_DISPLAY_DONE:
		break;

	case MENU_NOTIFY:
		fputs("smart_xmain: x_location: MENU_NOTIFY\n", stderr);
		break;

	case MENU_NOTIFY_DONE:
		break;
	}
	return item;
}

/*
 * Menu handler for `advanced_menu (Spec_file)'.
 */
Menu_item
x_spec_file(item, op)
	Menu_item	item;
	Menu_generate	op;
{
	smart_xmain_basewindow_objects * ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	switch (op) {
	case MENU_DISPLAY:
		break;

	case MENU_DISPLAY_DONE:
		break;

	case MENU_NOTIFY:
		fputs("smart_xmain: x_spec_file: MENU_NOTIFY\n", stderr);
		break;

	case MENU_NOTIFY_DONE:
		break;
	}
	return item;
}

/*
 * Menu handler for `advanced_menu (Dtext)'.
 */
Menu_item
x_dtext(item, op)
	Menu_item	item;
	Menu_generate	op;
{
	smart_xmain_basewindow_objects * ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	switch (op) {
	case MENU_DISPLAY:
		break;

	case MENU_DISPLAY_DONE:
		break;

	case MENU_NOTIFY:
		fputs("smart_xmain: x_dtext: MENU_NOTIFY\n", stderr);
		break;

	case MENU_NOTIFY_DONE:
		break;
	}
	return item;
}

/*
 * Menu handler for `advanced_menu (Dvec)'.
 */
Menu_item
x_dvec(item, op)
	Menu_item	item;
	Menu_generate	op;
{
	smart_xmain_basewindow_objects * ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	switch (op) {
	case MENU_DISPLAY:
		break;

	case MENU_DISPLAY_DONE:
		break;

	case MENU_NOTIFY:
		fputs("smart_xmain: x_dvec: MENU_NOTIFY\n", stderr);
		break;

	case MENU_NOTIFY_DONE:
		break;
	}
	return item;
}

/*
 * Menu handler for `advanced_menu (Drun)'.
 */
Menu_item
x_drun(item, op)
	Menu_item	item;
	Menu_generate	op;
{
	smart_xmain_basewindow_objects * ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	switch (op) {
	case MENU_DISPLAY:
		break;

	case MENU_DISPLAY_DONE:
		break;

	case MENU_NOTIFY:
		fputs("smart_xmain: x_drun: MENU_NOTIFY\n", stderr);
		break;

	case MENU_NOTIFY_DONE:
		break;
	}
	return item;
}

/*
 * Menu handler for `advanced_menu (Dsim)'.
 */
Menu_item
x_dsim(item, op)
	Menu_item	item;
	Menu_generate	op;
{
	smart_xmain_basewindow_objects * ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	switch (op) {
	case MENU_DISPLAY:
		break;

	case MENU_DISPLAY_DONE:
		break;

	case MENU_NOTIFY:
		fputs("smart_xmain: x_dsim: MENU_NOTIFY\n", stderr);
		break;

	case MENU_NOTIFY_DONE:
		break;
	}
	return item;
}

/*
 * Menu handler for `advanced_menu (Dmatch)'.
 */
Menu_item
x_dmatch(item, op)
	Menu_item	item;
	Menu_generate	op;
{
	smart_xmain_basewindow_objects * ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	switch (op) {
	case MENU_DISPLAY:
		break;

	case MENU_DISPLAY_DONE:
		break;

	case MENU_NOTIFY:
		fputs("smart_xmain: x_dmatch: MENU_NOTIFY\n", stderr);
		break;

	case MENU_NOTIFY_DONE:
		break;
	}
	return item;
}

/*
 * Menu handler for `advanced_menu (Qtext)'.
 */
Menu_item
x_qtext(item, op)
	Menu_item	item;
	Menu_generate	op;
{
	smart_xmain_basewindow_objects * ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	switch (op) {
	case MENU_DISPLAY:
		break;

	case MENU_DISPLAY_DONE:
		break;

	case MENU_NOTIFY:
		fputs("smart_xmain: x_qtext: MENU_NOTIFY\n", stderr);
		break;

	case MENU_NOTIFY_DONE:
		break;
	}
	return item;
}

/*
 * Menu handler for `advanced_menu (Qvec)'.
 */
Menu_item
x_qvec(item, op)
	Menu_item	item;
	Menu_generate	op;
{
	smart_xmain_basewindow_objects * ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	switch (op) {
	case MENU_DISPLAY:
		break;

	case MENU_DISPLAY_DONE:
		break;

	case MENU_NOTIFY:
		fputs("smart_xmain: x_qvec: MENU_NOTIFY\n", stderr);
		break;

	case MENU_NOTIFY_DONE:
		break;
	}
	return item;
}

/*
 * Menu handler for `advanced_menu (Qsim)'.
 */
Menu_item
x_qsim(item, op)
	Menu_item	item;
	Menu_generate	op;
{
	smart_xmain_basewindow_objects * ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	switch (op) {
	case MENU_DISPLAY:
		break;

	case MENU_DISPLAY_DONE:
		break;

	case MENU_NOTIFY:
		fputs("smart_xmain: x_qsim: MENU_NOTIFY\n", stderr);
		break;

	case MENU_NOTIFY_DONE:
		break;
	}
	return item;
}

/*
 * Menu handler for `advanced_menu (Qmatch)'.
 */
Menu_item
x_qmatch(item, op)
	Menu_item	item;
	Menu_generate	op;
{
	smart_xmain_basewindow_objects * ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	switch (op) {
	case MENU_DISPLAY:
		break;

	case MENU_DISPLAY_DONE:
		break;

	case MENU_NOTIFY:
		fputs("smart_xmain: x_qmatch: MENU_NOTIFY\n", stderr);
		break;

	case MENU_NOTIFY_DONE:
		break;
	}
	return item;
}

/*
 * Event callback function for `retrieve'.
 */
void
x_retrieve(item, event)
	Panel_item	item;
	Event		*event;
{
	smart_xmain_basewindow_objects	*ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fprintf(stderr, "smart_xmain: x_retrieve: event %d\n", event_id(event));
	panel_default_handle_event(item, event);
}

/*
 * Event callback function for `more'.
 */
void
x_more_documents(item, event)
	Panel_item	item;
	Event		*event;
{
	smart_xmain_basewindow_objects	*ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fprintf(stderr, "smart_xmain: x_more_documents: event %d\n", event_id(event));
	panel_default_handle_event(item, event);
}

/*
 * Notify callback function for `keywords'.
 */
void
x_keywords(item, event)
	Panel_item	item;
	Event		*event;
{
	smart_xmain_basewindow_objects	*ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fputs("smart_xmain: x_keywords\n", stderr);
}

/*
 * Notify callback function for `feedback'.
 */
void
x_feedback(item, event)
	Panel_item	item;
	Event		*event;
{
	smart_xmain_basewindow_objects	*ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fputs("smart_xmain: x_feedback\n", stderr);
}

/*
 * Event callback function for `next'.
 */
void
x_next_document(item, event)
	Panel_item	item;
	Event		*event;
{
	smart_xmain_basewindow_objects	*ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fprintf(stderr, "smart_xmain: x_next_document: event %d\n", event_id(event));
	panel_default_handle_event(item, event);
}

/*
 * Event callback function for `clear'.
 */
void
clear_usertext(item, event)
	Panel_item	item;
	Event		*event;
{
	smart_xmain_basewindow_objects	*ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fprintf(stderr, "smart_xmain: clear_usertext: event %d\n", event_id(event));
	panel_default_handle_event(item, event);
}

/*
 * Notify callback function for `help'.
 */
void
x_help(item, event)
	Panel_item	item;
	Event		*event;
{
	smart_xmain_basewindow_objects	*ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fputs("smart_xmain: x_help\n", stderr);
}

/*
 * Event callback function for `user_textpane'.
 */
Notify_value
x_hilite_button(win, event, arg, type)
	Xv_window	win;
	Event		*event;
	Notify_arg	arg;
	Notify_event_type type;
{
	smart_xmain_basewindow_objects	*ip = (smart_xmain_basewindow_objects *) xv_get(win, XV_KEY_DATA, INSTANCE);
	
	fprintf(stderr, "smart_xmain: x_hilite_button: event %d\n", event_id(event));
	
	if (event_action(event) == ACTION_DRAG_LOAD) {
		char	name[MAXPATHLEN];

		if (gdd_get_drag_name(win, name) != -1) {
			xv_set(win, TEXTSW_FILE, name, 0);
			return NOTIFY_DONE;
		}
	}
	
	return notify_next_event_func(win, (Notify_event) event, arg, type);
}

/*
 * Notify callback function for `title_list'.
 */
int
show_document(item, string, client_data, op, event)
	Panel_item	item;
	char		*string;
	Xv_opaque	client_data;
	Panel_list_op	op;
	Event		*event;
{
	smart_xmain_basewindow_objects	*ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	switch(op) {
	case PANEL_LIST_OP_DESELECT:
		fprintf(stderr, "smart_xmain: show_document: PANEL_LIST_OP_DESELECT: %s\n",string);
		break;

	case PANEL_LIST_OP_SELECT:
		fprintf(stderr, "smart_xmain: show_document: PANEL_LIST_OP_SELECT: %s\n",string);
		break;

	case PANEL_LIST_OP_VALIDATE:
		fprintf(stderr, "smart_xmain: show_document: PANEL_LIST_OP_VALIDATE: %s\n",string);
		break;

	case PANEL_LIST_OP_DELETE:
		fprintf(stderr, "smart_xmain: show_document: PANEL_LIST_OP_DELETE: %s\n",string);
		break;
	}
	return XV_OK;
}
