#include "stdafx.h"

#include "Application/Application.h"

////////////////////////////////////////////////////////////////////////////////
int32_t main([[maybe_unused]] int32_t argC, [[maybe_unused]] char* argV[])
{
	Application app;
	ReturnIf(!app.Init(), EXIT_FAILURE);

	app.RunApplication();

	return EXIT_SUCCESS;
}