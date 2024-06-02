/************************************************************************
*                                                                       *
*       Adding an X-Window interface to SMART --- smart_xmain.c         *
*                                                                       *
*                                                                       *
*    by: Victuria Chiu, senior in CS from Univ. of Cal. at Berkeley,    *
*                e-mail: victoria@csr.lbl.gov                           *
*                                                                       *
*        Tong Li, graduate student in CS from Oregon State University,  *
*                e-mail: lit@mist.cs.orst.edu                           *
*                                                                       *
*    at Lawrence berkeley Laboratory, Summer 1991                       *
*                                                                       *
************************************************************************/
/************************************************************************* */
/* smart_xmain.c - Notify and event callback function                      */
/*                                                                         */
/* for x-window interface to SMART system.                                 */
/* This original template file was generated by `gxv' from `smart_xmain.G'.*/
/***************************************************************************/

#include <stdio.h>
#include <strings.h>
#include <sys/param.h>
#include <sys/types.h>
#include <xview/xview.h>
#include <xview/panel.h>
#include <xview/textsw.h>
#include <xview/xv_xrect.h>
#include <xview/notice.h>
#include <gdd.h>
#include "smart_xmain_ui.h"
#include "smart_xsec_ui.h"
#include "xfunctions.h"
#include "param.h"

/*global vaiables and functions*/

int        row=0;
Textsw_index doc_last_insertion=0;
Textsw_index adv_last_insertion=0;

INTER_STATE is_x; 
COMMAND *parse_command_line();
void do_next_document();
void delete_text();

/*global window variables*/
smart_xmain_basewindow_objects          *smart_xmain_basewindow;
smart_xsec_document_popup_objects       *smart_xsec_document_popup;
smart_xsec_help_popup_objects           *smart_xsec_help_popup;
smart_xsec_savelast_popup_objects       *smart_xsec_savelast_popup;
smart_xsec_advance_popup_objects        *smart_xsec_advance_popup;

/*
 * Instance XV_KEY_DATA key.  An instance is a set of related
 * user interface objects.  A pointer to an object's instance
 * IS STOREd under this key in every object.  This must be a
 * global variable.
 */
Attr_attribute	INSTANCE;

void
xinterface(is)
INTER_STATE is;
{
	int check;
	int argc=1;
	char **arglist;

        arglist=(char **) malloc(100);
        arglist[0]=(char *) malloc(100);

        strcpy(arglist[0], "smart/smart");
	/*
	 * Initialize XView.
	 */

	check = xv_init(XV_INIT_ARGS, argc, arglist, NULL);
	if (check == 0) {
	  printf("xv_init failed.\n");
	  exit(0);
	}
	INSTANCE = xv_unique_key();
	
	/*
	 * Initialize user interface components.
	 */
	smart_xmain_basewindow = smart_xmain_basewindow_objects_initialize(NULL, NULL);
	
         smart_xsec_document_popup = smart_xsec_document_popup_objects_initialize(NULL, smart_xmain_basewindow->basewindow);
         smart_xsec_help_popup = smart_xsec_help_popup_objects_initialize(NULL, smart_xmain_basewindow->basewindow);
         smart_xsec_savelast_popup = smart_xsec_savelast_popup_objects_initialize(NULL,smart_xmain_basewindow->basewindow);
        smart_xsec_advance_popup = smart_xsec_advance_popup_objects_initialize(NULL, smart_xmain_basewindow->basewindow);

	/* assign global is_x to is for displaying help messages*/
	is_x=is; 

	/*set up help panel text*/
	textsw_insert(smart_xsec_help_popup->help_textpane, 
		      is_x.err_buf.buf, strlen(is_x.err_buf.buf)); 

	/*
	 * Turn control over to XView.
	 */
	xv_main_loop(smart_xmain_basewindow->basewindow);
	exit(0);
}

/*procedure that gets the first interger from a string*/

char *
get_doc_number(string)
char *string;
{
          char *buffer;
	  int i=0;

	  buffer = (char *) malloc (PATH_LEN);
	  bzero(buffer, PATH_LEN);
	  while( (*string == ' ') || (*string == '\t'))
	    string++;
	  while( (*string != ' ') && (*string != '\t'))
	    buffer[i++] = *string++;

	  buffer[i]=' ';

	  return buffer;
}


/*
 * Menu handler for `quit_menu (quit)'.
 * Note: nothing has been done when quit menu is selected. The quit_popup
 * Notify handle will generate a quit message. 
 */
Menu_item
x_quit(item, op)
	Menu_item	item;
	Menu_generate	op;
{
  
       int result;

	smart_xmain_basewindow_objects * ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	switch (op) {
	case MENU_DISPLAY:
		break;

	case MENU_DISPLAY_DONE:
		break;

	case MENU_NOTIFY:

	result = notice_prompt(smart_xmain_basewindow->basewindow, NULL, 
			NOTICE_FOCUS_XY, 500, 25,
			NOTICE_MESSAGE_STRINGS, 
			 "Do you really want to quit?", NULL,
			NOTICE_BUTTON_YES, "Yes",
			NOTICE_BUTTON_NO, "No", 
			NULL);

	if (result == NOTICE_YES)
	  if(xv_destroy_safe(smart_xmain_basewindow->basewindow) == XV_OK)
	    exit(1);

/*		fputs("smart_xmain: x_quit: MENU_NOTIFY\n", stderr);*/
		break;

	case MENU_NOTIFY_DONE:
		break;
	}
	return item;
}

/*
 * Menu handler for `quit_menu (xit)'.
 * Note: nothing has been done when xit menu is selected. The quit_popup
 * Notify handle will generate a quit message. 
 */
Menu_item
x_xit(item, op)
	Menu_item	item;
	Menu_generate	op;
{
        int         result;

	smart_xmain_basewindow_objects * ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	switch (op) {
	case MENU_DISPLAY:
		break;

	case MENU_DISPLAY_DONE:
		break;

	case MENU_NOTIFY:
	  result = notice_prompt(smart_xmain_basewindow->basewindow, NULL, 
			NOTICE_FOCUS_XY, 500, 25,
			NOTICE_MESSAGE_STRINGS, 
			 "Do you really want to quit?", NULL,
			NOTICE_BUTTON_YES, "Yes",
			NOTICE_BUTTON_NO, "No", 
			NULL);

	if (result == NOTICE_YES)
	  if(xv_destroy_safe(smart_xmain_basewindow->basewindow) == XV_OK)
	    exit(1);

/*		fputs("smart_xmain: x_xit: MENU_NOTIFY\n", stderr); */
		break;

	case MENU_NOTIFY_DONE:
		break;
	}
	return item;
}


/*
 * Notify callback function for `x_save'.
 */
void
x_save(item, event)
	Panel_item	item;
	Event		*event;
{

	smart_xmain_basewindow_objects	*ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);

       if (!(xv_get(smart_xmain_basewindow->save, PANEL_INACTIVE, FALSE))) 
	 
	 if (event_left_is_down(event))  {
	   xv_set(smart_xsec_savelast_popup->savelast_popup, XV_SHOW, TRUE, 0);
	 }
/*       fputs("smart_xmain: x_save: X_SAVE NOTIFY\n", stderr);*/
}

void 
do_advance(option)
char *option;
{

       char             in_buffer[PATH_LEN];
       COMMAND          *command;
       int              status;
       char             docend[50];        /*display End of document message*/
       char             command_buf[PATH_LEN];

       xv_set(smart_xmain_basewindow->general_msg, PANEL_LABEL_STRING, 
	      "doing advance functions...", 0);
       strcpy(command_buf, option);

       is_x.output_buf.end = 0;
       is_x.err_buf.end = 0;
       strcpy(in_buffer, option);
	 
       if (NULL != (command = parse_command_line(in_buffer,&is_x))) { 
	 if (-1 == (status = command->proc.proc (&is_x, (char *) NULL)) 
	     || command->end_inter) 
	   printf("advanced: error in %s\n",option);
       } 

	 is_x.output_buf.buf[is_x.output_buf.end] = '\0';
	 if (is_x.output_buf.buf == NULL) {
	   is_x.err_buf.buf[is_x.err_buf.end] = '\0';
	   xv_set(smart_xmain_basewindow->general_msg, PANEL_LABEL_STRING, 
		  is_x.err_buf.buf, NULL);
	 }
	 else {
/*displaying document inside advance text panel*/
	   
	   strcpy(docend,"\n************** Advance function ");
	   strcat(docend, option);
	   strcat(docend, " **************\n\n");
	   textsw_insert(smart_xsec_advance_popup->doc_textpane1, 
			 docend, strlen(docend));
	   xv_set(smart_xsec_advance_popup->doc_textpane1, 
		  TEXTSW_INSERTION_POINT, TEXTSW_INFINITY, NULL);
	   textsw_insert(smart_xsec_advance_popup->doc_textpane1, 
			 is_x.output_buf.buf, strlen(is_x.output_buf.buf));
	   textsw_possibly_normalize(smart_xsec_advance_popup->doc_textpane1,
				     adv_last_insertion);
	   adv_last_insertion = (Textsw_index) xv_get(
	      smart_xsec_advance_popup->doc_textpane1, TEXTSW_INSERTION_POINT);
	 }
	 xv_set(smart_xsec_advance_popup->advance_popup, XV_SHOW, TRUE, NULL);
	   strcpy(docend," Advance function ");
	   strcat(docend, option);
       xv_set(smart_xmain_basewindow->general_msg, PANEL_LABEL_STRING, 
	      docend, 0);
}

/*converts a number to a string*/

char *
itoa(num)
int num;
{
  char  string[10];
  int i=0;
  int u, v;
  char c;

  do {
    string[i++] = num % 10 + '0';        /*get next digit*/
  } while ((num/= 10) > 0);
  string[i]='\0';

/*reversing string*/
  for (u = 0, v = strlen(string) - 1; u < v; u++, v--) {
    c = string[u];
    string[u] = string[v];
    string[v] = c;
  }
  return string;
}


/*prepare_command gets all the necessary arguemnts then calls do_advance
 *to execute the command.
 */

void
do_advance_args(option, argnum)
char *option;
int argnum;
{
        char *command_buf;
	char *string;
	char err_msg[PATH_LEN];
	int  numofdoc=0;
	int i=0;

	command_buf= (char  *) malloc(PATH_LEN);
	bzero(command_buf,PATH_LEN);
	strcpy(command_buf, option);

	while( ((i <= row) && (numofdoc != argnum))) {
	  if (xv_get(smart_xmain_basewindow->title_list, 
		     PANEL_LIST_SELECTED, i) == TRUE) {
	    numofdoc++;
	    string=(char *) xv_get(smart_xmain_basewindow->title_list, 
				   PANEL_LIST_STRING, i);
	    strcat (command_buf, get_doc_number(string));
	  }
	  i++;
	}
	if (numofdoc != argnum) {
	  strcpy(err_msg, option);
	  strcat(err_msg, " :  ");
	  strcat(err_msg, itoa(argnum));
	  strcat(err_msg, " document(s) must be selected.");
	  xv_set(smart_xmain_basewindow->general_msg, PANEL_LABEL_STRING, 
		 err_msg, 0);
	}
	else do_advance(command_buf);
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
		do_advance("Raw_doc");
/*		fputs("smart_xmain: x_raw_doc: MENU_NOTIFY\n", stderr); */
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
		do_advance("Top_ranked");
/*		fputs("smart_xmain: x_top_ranked: MENU_NOTIFY\n", stderr); */
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
		do_advance("Location");
/*		fputs("smart_xmain: x_location: MENU_NOTIFY\n", stderr); */
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
		do_advance("Spec_file");
/*		fputs("smart_xmain: x_spec_file: MENU_NOTIFY\n", stderr); */
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
		do_advance_args("Dtext ", 1);
/*		fputs("smart_xmain: x_dtext: MENU_NOTIFY\n", stderr); */

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
		do_advance_args("Dvec ", 1);
/*		fputs("smart_xmain: x_dvec: MENU_NOTIFY\n", stderr); */
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
		do_advance_args("Drun ",1);
/*		fputs("smart_xmain: x_drun: MENU_NOTIFY\n", stderr); */
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
		do_advance_args("Dsim ", 2);
/*		fputs("smart_xmain: x_dsim: MENU_NOTIFY\n", stderr); */
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
		do_advance_args("Dmatch ", 2);
/*		fputs("smart_xmain: x_dmatch: MENU_NOTIFY\n", stderr); */
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
		do_advance("Qtext");
/*		fputs("smart_xmain: x_qtext: MENU_NOTIFY\n", stderr); */
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
		do_advance("Qvec");
/*		fputs("smart_xmain: x_qvec: MENU_NOTIFY\n", stderr); */
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
		do_advance_args("Qsim ", 1);
/*		fputs("smart_xmain: x_qsim: MENU_NOTIFY\n", stderr); */
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
		do_advance_args("Qmatch ", 1);
/*		fputs("smart_xmain: x_qmatch: MENU_NOTIFY\n", stderr); */
		break;

	case MENU_NOTIFY_DONE:
		break;
	}
	return item;
}


void 
print_titles()
{
  char       *title;

  title = (char *) malloc (strlen (is_x.output_buf.buf) +1);
  strcpy(title, is_x.output_buf.buf);
  title = (char *) strtok(title, "\n");

/*printing out documents for selection*/
  
  while( (title = (char *) strtok(NULL, "\n")) !=NULL) {
    row = xv_get(smart_xmain_basewindow->title_list, PANEL_LIST_NROWS);
    xv_set(smart_xmain_basewindow->title_list, 
	   PANEL_LIST_STRING, row, title, NULL);
  }
}

void
clear_title_list()
{
/*delete existing lists*/

  if (row > 0) 
    for (; row >= 0; row--) {
      xv_set(smart_xmain_basewindow->title_list, PANEL_LIST_DELETE, row, NULL);
    }
}

void
delete_text(textpane)
Textsw  textpane;
{
/*enable write to delete*/
	  xv_set(textpane,
		 TEXTSW_BROWSING, FALSE,
		 TEXTSW_DISABLE_LOAD, FALSE,
		 NULL);
	  textsw_erase(textpane, 0,TEXTSW_INFINITY);

/*disable write after delete*/
	  xv_set(textpane,
		 TEXTSW_BROWSING, TRUE,
		 TEXTSW_DISABLE_LOAD, TRUE,
		 NULL);
}

void
hilite_buttons()
{
/*hilite all the buttons needed after retrieve*/

  if (xv_get(smart_xmain_basewindow->more, PANEL_INACTIVE, TRUE)) {
    xv_set(smart_xmain_basewindow->more, PANEL_INACTIVE, FALSE, NULL);
    xv_set(smart_xmain_basewindow->next, PANEL_INACTIVE, FALSE, NULL);
    xv_set(smart_xmain_basewindow->advanced, PANEL_INACTIVE, FALSE, NULL);
    xv_set(smart_xmain_basewindow->feedback, PANEL_INACTIVE, FALSE, NULL);
  }
}


void
unhilite_buttons()
{
/*hilite all the buttons needed after retrieve*/

  if (!(xv_get(smart_xmain_basewindow->more, PANEL_INACTIVE, TRUE))) {
    xv_set(smart_xmain_basewindow->more, PANEL_INACTIVE, TRUE, NULL);
    xv_set(smart_xmain_basewindow->next, PANEL_INACTIVE, TRUE, NULL);
    xv_set(smart_xmain_basewindow->advanced, PANEL_INACTIVE, TRUE, NULL);
    xv_set(smart_xmain_basewindow->feedback, PANEL_INACTIVE, TRUE, NULL);
  }
}

/*
 * Event callback function for `retrieve'.
 */
void
x_retrieve(item, event)
	Panel_item	item;
	Event		*event;
{
       char             query_buf[PATH_LEN];
       char             in_buffer[PATH_LEN];
       char             err_msg[PATH_LEN];
       COMMAND          *command;
       int              status;
       Textsw_index     next_pos;

       smart_xmain_basewindow_objects	*ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);

/*execute if retrieve button is active*/

       if (!(xv_get(smart_xmain_basewindow->retrieve, PANEL_INACTIVE, FALSE))) {
	 if (event_left_is_down(event)) {

/* get query from text panel*/
	      
	   next_pos = (Textsw_index) xv_get(
		      smart_xmain_basewindow->user_textpane, 
		      TEXTSW_CONTENTS, 0, query_buf, PATH_LEN-1);
	   if (next_pos = PATH_LEN-1)
	     query_buf[PATH_LEN] = '\0';
	   else query_buf[next_pos +1] = '\0';

	   xv_set(ip->general_msg, PANEL_LABEL_STRING, "retrieving...", 0);
	   is_x.output_buf.end = 0;
	   is_x.err_buf.end = 0;
	   strcpy(in_buffer, "retrieve");

/*call smart to do retrieve*/

	   if (NULL != (command = parse_command_line(in_buffer,&is_x))) { 
	     if (-1 == (status = command->proc.proc (&is_x, query_buf)) 
		 || command->end_inter) 
	       printf("x_retrieve: error in retrieving\n");
	   } 

/*display titles to x-window*/

	   clear_title_list();
	   delete_text(smart_xsec_document_popup->doc_textpane);
	   delete_text(smart_xsec_advance_popup->doc_textpane1);

	   if (is_x.output_buf.end == 0) {
	     is_x.err_buf.buf[is_x.err_buf.end] = '\0';
	     xv_set(ip->general_msg,PANEL_LABEL_STRING,is_x.err_buf.buf, NULL);
	     unhilite_buttons();
	   }
	   else {
	     is_x.output_buf.buf[is_x.output_buf.end] = '\0';
	     hilite_buttons();
	     print_titles();
/*print messsage*/
	     bzero(err_msg, PATH_LEN);
	     strcpy(err_msg, itoa(row +1));
	     strcat(err_msg, " document(s) retrieved.");
	     xv_set(smart_xmain_basewindow->general_msg, 
		    PANEL_LABEL_STRING,err_msg , 0);
	   }
	 }
       }
       
/*       fprintf(stderr, "smart_xmain: x_retrieve: event %d\n", event_id(event)); */
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
       char             in_buffer[PATH_LEN];
       char             err_msg[PATH_LEN];
       COMMAND          *command;
       int              status;
       int              last_row_count;

       smart_xmain_basewindow_objects	*ip = (smart_xmain_basewindow_objects *)
	  xv_get(item, XV_KEY_DATA, INSTANCE);

       if (!(xv_get(smart_xmain_basewindow->more, PANEL_INACTIVE, FALSE))) {
	 if (event_left_is_down(event)) {
	   xv_set(ip->general_msg, PANEL_LABEL_STRING, 
		  "retrieving more documents...", 0);	

	   last_row_count = row;          
	   is_x.output_buf.end = 0;
	   strcpy(in_buffer, "more");

/*call smart to do "more"*/	 

	   if (NULL != (command = parse_command_line(in_buffer,&is_x))) { 
	     if (-1 == (status = command->proc.proc (&is_x, (char *) NULL)) 
		 || command->end_inter) 
	       printf("x_more: error in more retrieve\n");
	   } 

/*display to title list panel*/

	   is_x.output_buf.buf[is_x.output_buf.end] = '\0';
	   clear_title_list();
	   print_titles();
	   if (last_row_count == row)
	     xv_set(ip->general_msg, PANEL_LABEL_STRING, 
		    "No more documents retrieved.", NULL);
	   else {
/*print message*/ 	   
	     bzero(err_msg, PATH_LEN);
	     strcpy(err_msg, itoa(row - last_row_count -1));
	     strcat(err_msg, " more document(s) retrieved.");
	     xv_set(smart_xmain_basewindow->general_msg, 
		    PANEL_LABEL_STRING,err_msg , 0);
	   }
	 }
       }
/*       fprintf(stderr, "smart_xmain: x_more_documents: event %d\n", event_id(event)); */
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
	
	   xv_set(ip->general_msg, PANEL_LABEL_STRING, 
		  "Keyword option will be implemented.", NULL);

/*	fputs("smart_xmain: x_keywords\n", stderr); */
}


/*
 * Notify callback function for `feedback'.
 */
void
x_feedback(item, event)
	Panel_item	item;
	Event		*event;
{
       char             in_buffer[PATH_LEN];    
       char             err_msg[PATH_LEN];      
       int              last_row_count;        
       char             *string;
       COMMAND          *command;
       int              status;
       int              i;

       smart_xmain_basewindow_objects	*ip = 
         (smart_xmain_basewindow_objects *) xv_get(item,XV_KEY_DATA, INSTANCE);

       if (! (xv_get(smart_xmain_basewindow->feedback, PANEL_INACTIVE,FALSE))){
	 if (event_left_is_down(event)) {
	  xv_set(ip->general_msg, PANEL_LABEL_STRING, 
		 "doing feedback query on useful documents...", 0);

	  is_x.output_buf.end = 0; 
	  bzero(in_buffer,PATH_LEN);
	  last_row_count = row;

/*prepare command for calling smart*/

          strcpy(in_buffer, "feedback ");
/*add numbers*/ 
	  for (i = 0; i <= row; i++) 
	    if (xv_get(smart_xmain_basewindow->title_list, 
		       PANEL_LIST_SELECTED, i) == TRUE) {
	      string = (char *) xv_get(smart_xmain_basewindow->title_list, 
			PANEL_LIST_STRING, i);
	      strcat(in_buffer, get_doc_number(string));
	    }

	  if (NULL != (command = parse_command_line(in_buffer , &is_x))) { 
	    if (-1 == (status = command->proc.proc (&is_x, (char *) NULL)) 
		|| command->end_inter) {
	      printf("x_feedback: error in feedback retrieve\n");
	    }
	  }
	    
	  is_x.output_buf.buf[is_x.output_buf.end] = '\0';
	  clear_title_list();
	  print_titles();

/*display to title list panel*/

	   if (last_row_count == row)
	     xv_set(ip->general_msg, PANEL_LABEL_STRING, 
		    "No feedback document retrieved", NULL);
	   else {
/*print message*/ 	   
	     bzero(err_msg, PATH_LEN);
	     strcpy(err_msg, itoa(row - last_row_count -1));
	     strcat(err_msg, " feedback document(s) retrieved.");
	     xv_set(smart_xmain_basewindow->general_msg, 
		    PANEL_LABEL_STRING,err_msg , 0);
	   }
	 }
       }

/*       fputs("smart_xmain: x_feedback\n", stderr);*/
}


/*display_doc_text formats the returned description of a document into 
 *different catagories such as document id, title, author, abstration, etc.
 */

void
display_doc_text()
{
  char      displayline[PATH_LEN];
  char      *text;

  xv_set(smart_xsec_document_popup->doc_textpane, 
	 TEXTSW_INSERTION_POINT, TEXTSW_INFINITY, NULL);

  text = (char *) malloc (strlen (is_x.output_buf.buf) +1);
  strcpy(text, is_x.output_buf.buf);
  text = (char *) strtok(text, "\n");

  while (text !=NULL) {
    if (*text == '.') {
      text++;
      switch(*text) {
      case 'I':  strcpy(displayline, "Document ID:");
	         text++;
                 strcat(displayline, text);
	         strcat(displayline, "\n");
	         break;
      case 'T':  strcpy(displayline, "\nTitle:\n");
                 break;
      case 'A':  strcpy(displayline, "\nAuthor:\n");
                 break;
      case 'W':  strcpy(displayline, "\nAbstract:\n");
                 break;
      default:   strcpy(displayline, ".");
	         strcat(displayline, text);
	         break;
      }
      textsw_insert(smart_xsec_document_popup->doc_textpane, 
		    displayline, strlen(displayline));    
      bzero(displayline, PATH_LEN);
    }
    else {
      strcpy(displayline, text);
      strcat(displayline, "\n");
      textsw_insert(smart_xsec_document_popup->doc_textpane,
		    displayline,strlen(displayline));
    }
    text = (char *) strtok(NULL, "\n");
  }

  strcpy(displayline,"\n**************End of Document**************\n\n");

  textsw_insert(smart_xsec_document_popup->doc_textpane, 
		displayline, strlen(displayline)); 
  textsw_possibly_normalize(smart_xsec_document_popup->doc_textpane,
			    doc_last_insertion);
  doc_last_insertion = (Textsw_index) xv_get(
	 smart_xsec_document_popup->doc_textpane, TEXTSW_INSERTION_POINT);
}



/*prepares command to call smart to do "next". Used by both x_next_document
 *and x_docnext_document.
 */

void
do_next_document(event)
     Event		*event;
{

  char             in_buffer[PATH_LEN];
  COMMAND          *command;
  int              status;
  char             docend[50];        /*display End of document message*/

  if (!(xv_get(smart_xmain_basewindow->next, PANEL_INACTIVE, FALSE))) {
    if (event_left_is_down(event)) {
      xv_set(smart_xmain_basewindow->general_msg, PANEL_LABEL_STRING, 
	     "displaying the next document...", 0);

      is_x.output_buf.end = 0;
      is_x.err_buf.end = 0;
      strcpy(in_buffer, "next");
	 
      if (NULL != (command = parse_command_line(in_buffer,&is_x))) { 
	if (-1 == (status = command->proc.proc (&is_x, (char *) NULL)) 
	    || command->end_inter) 
	  printf("x_more: error in more retrieve\n");
      } 

      is_x.output_buf.buf[is_x.output_buf.end] = '\0';
      if (is_x.output_buf.end == 0) {
	is_x.err_buf.buf[is_x.err_buf.end] = '\0';
	xv_set(smart_xmain_basewindow->general_msg, PANEL_LABEL_STRING, is_x.err_buf.buf, NULL);
      }
      else {
	xv_set(smart_xsec_document_popup->document_popup,XV_SHOW,TRUE,NULL);

/*displaying document inside text panel*/
	display_doc_text();

	strcpy(docend, "Next document displayed.");
	xv_set(smart_xmain_basewindow->general_msg, PANEL_LABEL_STRING, 
	       docend,0);
      }
    }
  }
}
  
/*
 * Event callback function for `next'.
 */
void
x_next_document(item, event)
	Panel_item	item;
	Event		*event;
{

  smart_xmain_basewindow_objects *ip = 
    (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);

  do_next_document(event);
/*  fprintf(stderr, "smart_xmain: x_next_document: event %d\n", event_id(event));*/
}

/*
 * Event callback function for `clear'.
 * It clears the user text panel, and inactivate the retrieve button.
 */
void
clear_usertext(item, event)
	Panel_item	item;
	Event		*event;
{
	smart_xmain_basewindow_objects	*ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);

	if (event_left_is_down(event)) {
	  xv_set(ip->general_msg, PANEL_LABEL_STRING, "Enter natural language query below and press the Retrieve Button.", 0);
	  textsw_erase(smart_xmain_basewindow->user_textpane, 0,TEXTSW_INFINITY);
	  xv_set(smart_xmain_basewindow->retrieve, PANEL_INACTIVE, TRUE, NULL);
	}

/*	fprintf(stderr, "smart_xmain: clear_usertext: event %d\n", event_id(event)); */
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

	xv_set(smart_xsec_help_popup->help_popup, XV_SHOW, TRUE, 0);

	if (!xv_get(smart_xsec_help_popup->help_textpane, TEXTSW_MODIFIED, NULL)) {

	  textsw_insert(smart_xsec_help_popup->help_textpane, is_x.err_buf.buf, strlen(is_x.err_buf.buf)); 
	}
/*	fputs("smart_xmain: x_help\n", stderr); */
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
	
/*	fprintf(stderr, "smart_xmain: x_hilite_button: event %d\n", event_id(event));
*/
	if (xv_get(smart_xmain_basewindow->user_textpane, TEXTSW_MODIFIED)
	     && xv_get(smart_xmain_basewindow->retrieve, PANEL_INACTIVE, TRUE)) {
	  xv_set(smart_xmain_basewindow->retrieve, PANEL_INACTIVE, FALSE, NULL);
	  xv_set(smart_xmain_basewindow->save, PANEL_INACTIVE, FALSE, NULL);
	}

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
/*connecting smart application variables*/

       char             in_buffer[PATH_LEN];
       COMMAND          *command;
       int              status;

/*local variables*/
       char             err_msg[PATH_LEN];
       char             *doc_id;

	smart_xmain_basewindow_objects	*ip = (smart_xmain_basewindow_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	switch(op) {
	case PANEL_LIST_OP_DESELECT:

	  is_x.output_buf.end = 0;
	  is_x.err_buf.end = 0;
	  strcpy (in_buffer, doc_id=get_doc_number(string)); 

/*call smart*/

	  if (NULL != (command = parse_command_line(in_buffer,&is_x))) {
	    if (-1 == (status = command->proc.proc (&is_x, (char *) NULL)) 
		|| command->end_inter) {
	      printf("x_show_document: error in show document\n");
	    }
	  }

	  is_x.output_buf.buf[is_x.output_buf.end] = '\0';
	  is_x.err_buf.buf[is_x.err_buf.end] = '\0';

/*check smart output*/

	  if (strcmp(is_x.output_buf.buf,"") == 0)
	    xv_set(ip->general_msg, PANEL_LABEL_STRING, 
		   "Not a vaild document selected", 0);	
	  else {
 	   xv_set(smart_xsec_document_popup->document_popup,XV_SHOW,TRUE,NULL);

/*displaying document inside text panel*/
	   display_doc_text();

/*print message*/ 	   
	   bzero(err_msg, PATH_LEN);
	   strcpy(err_msg, "Displaying document ");
	   strcat(err_msg, doc_id);
	   xv_set(smart_xmain_basewindow->general_msg, 
		  PANEL_LABEL_STRING,err_msg , 0);
	 }
	  break;

	case PANEL_LIST_OP_SELECT:
/*		fprintf(stderr, "smart_xmain: show_document: PANEL_LIST_OP_SELECT: %s\n",string); */
		break;

	case PANEL_LIST_OP_VALIDATE:
/*		fprintf(stderr, "smart_xmain: show_document: PANEL_LIST_OP_VALIDATE: %s\n",string);*/
		break;

	case PANEL_LIST_OP_DELETE:
/*		fprintf(stderr, "smart_xmain: show_document: PANEL_LIST_OP_DELETE: %s\n",string); */
		break;
	}
	return XV_OK;
}



