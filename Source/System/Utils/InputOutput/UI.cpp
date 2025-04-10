#include "stdafx.h"

#include "System/Utils/InputOutput/UI.h"

#if defined(_WINDOWS)
#include <Windows.h>

#elif defined(_LINUX)
//#include <gtk/gtk.h>

#else
#error Not intended to run on this system.

#endif

namespace UI
{
////////////////////////////////////////////////////////////////////////////////
void ShowMessageBoxOK(const std::string& title, const std::string& text, EMessageBoxIcon icon)
{
#if defined(_WINDOWS)
    int icon_flag
        = icon == EMessageBoxIcon::Error ? MB_ICONERROR
        : icon == EMessageBoxIcon::Warning ? MB_ICONWARNING
        : icon == EMessageBoxIcon::Info ? MB_ICONINFORMATION
        : MB_ICONINFORMATION;

    MessageBoxA(nullptr, text.c_str(), title.c_str(), MB_OK | MB_SYSTEMMODAL | icon_flag);

#elif defined(_LINUX)
    /*GtkMessageType gtk_message_type
        = icon == EMessageBoxIcon::Error ? GTK_MESSAGE_ERROR
        : icon == EMessageBoxIcon::Warning ? GTK_MESSAGE_WARNING
        : icon == EMessageBoxIcon::Info ? GTK_MESSAGE_INFO
        : GTK_MESSAGE_INFO;

    GtkWidget* p_dialog = gtk_message_dialog_new(nullptr, GTK_DIALOG_DESTROY_WITH_PARENT,
        gtk_message_type, GTK_BUTTONS_OK_CANCEL, "%s\n\n%s", p_title, p_message);

    gtk_dialog_run(GTK_DIALOG(p_dialog));
    gtk_widget_destroy(p_dialog);*/

#else
#error Not intended to run on this system.

#endif
}
} // !namespace UI