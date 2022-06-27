// draw.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "draw2.h"
#include <vector>
#include <cstdio>
#include <string>
#define MAX_LOADSTRING 100
#define TMR_1 1

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

INT value;
struct Elevator
{
	int people_at_elevator = 0;
	int how_many1 = 0;
	int how_many2 = 0;
	int how_many3 = 0;
	int how_many4 = 0;
	int how_many5 = 0;
	int waiting_people = 0;
};
// buttons
HWND hwndButton;

// sent data
int col = 0;
int pietro = 1;
int a = 0;
int draw_people = 0;
bool if_going = false;

Elevator elevator;
std::vector<Point> data;
RECT drawArea1 = { 499, 39, 641, 631 };
RECT drawArea2 = { 10, 37, 490, 218 };//5pietro
RECT drawArea3 = { 10, 222, 490, 423 };//3pietro
RECT drawArea4 = { 10, 427, 490, 628 };//1pietro
RECT drawArea5 = { 645, 105, 1130, 308 };//4pietro
RECT drawArea6 = { 645, 312, 1130, 513 };//2 pietro
RECT textArea1 = { 180, 40, 530, 600 };
RECT textArea2 = { 240, 40, 530, 600 };
RECT textArea3 = { 182, 20, 500, 600 };
RECT textArea4 = { 240, 20, 500, 600 };

RectF ellipseRect(70.0f, 330.0f, 20.0f, 20.0f);
RectF ellipseRect2(70.0f, 535.0f, 20.0f, 20.0f);
RectF ellipseRect3(1040.0f, 405.0f, 20.0f, 20.0f);
RectF ellipseRect4(1040.0f, 205.0f, 20.0f, 20.0f);
RectF ellipseRect5(70.0f, 120.0f, 20.0f, 20.0f);
RectF ellipseRect6(620.0f, 550.0f, 20.0f, 20.0f);
RectF ellipseRect7(70.0f, 535.0f, 20.0f, 20.0f);
// Forward declarations of functions included in this code module:

ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	Buttons(HWND, UINT, WPARAM, LPARAM);


void MyOnPaint(HDC hdc, int pietro)
{
	Graphics graphics(hdc);
	Pen pen(Color(255, 0, 0, 255));
	Pen pen2(Color(255, 25 * col, 0, 255));

	//	for (int i = 1; i < 100; i++)
	//		graphics.DrawLine(&pen2, data[i - 1].X, data[i - 1].Y, data[i].X, data[i].Y);

	graphics.DrawRectangle(&pen2, 497, 37, 146, 600);//kanal

	switch (pietro)
	{
	case 1:graphics.DrawRectangle(&pen2, 500, 450 + a, 140, 180);//1 pietro winda
		break;
	case 2:graphics.DrawRectangle(&pen2, 500, 335 + a, 140, 180);//2 pietro winda
		break;
	case 3:graphics.DrawRectangle(&pen2, 500, 245 + a, 140, 180);//3 pietro winda
		break;
	case 4:graphics.DrawRectangle(&pen2, 500, 130 + a, 140, 180);//4 pietro winda
		break;
	case 5:graphics.DrawRectangle(&pen2, 500, 40 + a, 140, 180); //5 pietro winda
		break;
	default:
		break;
	}
	
	graphics.DrawLine(&pen2, 10, 220, 497, 220); //5 pietro podloga
	graphics.DrawLine(&pen2, 10, 425, 497, 425); //3 pietro podloga
	graphics.DrawLine(&pen2, 10, 630, 497, 630); //1 pietro podloga

	graphics.DrawLine(&pen2, 643, 310, 1130, 310); //4 pietro podloga
	graphics.DrawLine(&pen2, 643, 515, 1130, 515); //2 pietro podloga

	switch (draw_people)
	{
	case 1:graphics.DrawLine(&pen2, 80, 555, 80, 601); // czlon
		graphics.DrawLine(&pen2, 80, 599, 90, 629); //prawa noga
		graphics.DrawLine(&pen2, 80, 599, 70, 629); //lewa noga
		graphics.DrawLine(&pen2, 80, 555, 90, 601); // prawa reka
		graphics.DrawLine(&pen2, 80, 555, 70, 601); //lewa reka
		graphics.DrawEllipse(&pen2, ellipseRect2);  //glowa 
		break;

	case 2:graphics.DrawLine(&pen2, 1050, 425, 1050, 480); 
		graphics.DrawLine(&pen2, 1050, 474, 1060, 515); 
		graphics.DrawLine(&pen2, 1050, 474, 1040, 515); 
		graphics.DrawLine(&pen2, 1050, 425, 1060, 480); 
		graphics.DrawLine(&pen2, 1050, 425, 1040, 480); 
		graphics.DrawEllipse(&pen2, ellipseRect3);  
		break;

	case 3:graphics.DrawLine(&pen2, 80, 350, 80, 396); 
		graphics.DrawLine(&pen2, 80, 394, 90, 424); 
		graphics.DrawLine(&pen2, 80, 394, 70, 424); 
		graphics.DrawLine(&pen2, 80, 350, 90, 396); 
		graphics.DrawLine(&pen2, 80, 350, 70, 396); 
		graphics.DrawEllipse(&pen2, ellipseRect);  
		break;

	case 4:graphics.DrawLine(&pen2, 1050, 225, 1050, 271); 
		graphics.DrawLine(&pen2, 1050, 269, 1060, 309); 
		graphics.DrawLine(&pen2, 1050, 269, 1040, 309); 
		graphics.DrawLine(&pen2, 1050, 225, 1060, 271); 
		graphics.DrawLine(&pen2, 1050, 225, 1040, 271); 
		graphics.DrawEllipse(&pen2, ellipseRect4); 
		break;

	case 5:graphics.DrawLine(&pen2, 80, 140, 80, 186); 
		graphics.DrawLine(&pen2, 80, 184, 90, 220); 
		graphics.DrawLine(&pen2, 80, 184, 70, 220); 
		graphics.DrawLine(&pen2, 80, 140, 90, 186); 
		graphics.DrawLine(&pen2, 80, 140, 70, 186); 
		graphics.DrawEllipse(&pen2, ellipseRect5);  
		break;
	case 6: graphics.DrawRectangle(&pen2, 600, 590 + a, 20, 40);
		break;
	case 7: graphics.DrawRectangle(&pen2, 600, 475 + a, 20, 40);
		break;
	case 8:graphics.DrawRectangle(&pen2, 600, 385 + a, 20, 40);
		break;
	case 9: graphics.DrawRectangle(&pen2, 600, 270 + a, 20, 40);
		break;
	case 10: graphics.DrawRectangle(&pen2, 600, 180 + a, 20, 40);
		break;
	}

	LPCWSTR a = L" People:";
	DrawText(hdc, a, 14, &textArea1, DT_TOP);
	wchar_t buffer1[2];
	wsprintfW(buffer1, L"%i", elevator.people_at_elevator);
	DrawText(hdc, buffer1, 1, &textArea2, DT_BOTTOM | DT_INTERNAL);
	LPCWSTR b = L"Weight:";
	DrawText(hdc, b, 14, &textArea3, DT_TOP);
	wchar_t buffer2[4];
	wsprintfW(buffer2, L"%i", (elevator.people_at_elevator * 70));
	DrawText(hdc, buffer2, 3, &textArea4, DT_BOTTOM | DT_INTERNAL);
}



void repaintWindow(HWND hWnd, HDC& hdc, PAINTSTRUCT& ps, RECT* drawArea)
{
	if (drawArea == NULL)
		InvalidateRect(hWnd, NULL, TRUE); // repaint all
	else
		InvalidateRect(hWnd, drawArea, TRUE); //repaint drawArea
	hdc = BeginPaint(hWnd, &ps);
	MyOnPaint(hdc, pietro);
	EndPaint(hWnd, &ps);
}

void inputData()
{
	data.push_back(Point(0, 0));
	for (int i = 1; i < 100; i++) {
		data.push_back(Point(2 * i + 1, 200 * rand() / RAND_MAX));
	}
}
int OnCreate(HWND window)
{
	inputData();
	return 0;
}

// main function (exe hInstance)
int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	value = 0;

	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DRAW, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);



	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DRAW));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	GdiplusShutdown(gdiplusToken);

	return (int)msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DRAW));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_DRAW);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;


	hInst = hInstance; // Store instance handle (of exe) in our global variable

	// main window
	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	// create button and store the handle                                                       


	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("DrawAll"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		0, 0,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON99,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	//############# 1 pietro  #############
	hwndButton = CreateWindow(TEXT("button"),                      
		TEXT("2"),                  
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  
		10, 600,                                  
		29, 29,                              
		hWnd,                                 
		(HMENU)ID_BUTTON1,                   
		hInstance,                            
		NULL);

	hwndButton = CreateWindow(TEXT("button"),
		TEXT("3"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		10, 570,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON2,
		hInstance,
		NULL);
	hwndButton = CreateWindow(TEXT("button"),
		TEXT("4"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		10, 540,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON3,
		hInstance,
		NULL);
	hwndButton = CreateWindow(TEXT("button"),
		TEXT("5"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		10, 510,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON4,
		hInstance,
		NULL);
	hwndButton = CreateWindow(TEXT("button"),
		TEXT("W"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		10, 480,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON5,
		hInstance,
		NULL);
	hwndButton = CreateWindow(TEXT("button"),
		TEXT("+1"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		10, 450,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON29,
		hInstance,
		NULL);
	hwndButton = CreateWindow(TEXT("button"),
		TEXT(">"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		40, 450,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON32,
		hInstance,
		NULL);
	//################# 3 pietro  ############################

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("1"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		10, 395,                                  // the left and top co-ordinates
		29, 29,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON6,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),
		TEXT("2"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		10, 365,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON7,
		hInstance,
		NULL);
	hwndButton = CreateWindow(TEXT("button"),
		TEXT("4"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		10, 335,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON8,
		hInstance,
		NULL);
	hwndButton = CreateWindow(TEXT("button"),
		TEXT("5"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		10, 305,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON9,
		hInstance,
		NULL);
	hwndButton = CreateWindow(TEXT("button"),
		TEXT("W"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		10, 275,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON10,
		hInstance,
		NULL);
	hwndButton = CreateWindow(TEXT("button"),
		TEXT("+1"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		10, 245,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON26,
		hInstance,
		NULL);
	hwndButton = CreateWindow(TEXT("button"),
		TEXT(">"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		40, 245,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON33,
		hInstance,
		NULL);
	//################# 5 pietro  ############################

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("1"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		10, 190,                                  // the left and top co-ordinates
		29, 29,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON11,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),
		TEXT("2"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		10, 160,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON12,
		hInstance,
		NULL);
	hwndButton = CreateWindow(TEXT("button"),
		TEXT("3"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		10, 130,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON13,
		hInstance,
		NULL);
	hwndButton = CreateWindow(TEXT("button"),
		TEXT("4"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		10, 100,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON14,
		hInstance,
		NULL);
	hwndButton = CreateWindow(TEXT("button"),
		TEXT("W"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		10, 70,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON15,
		hInstance,
		NULL);
	hwndButton = CreateWindow(TEXT("button"),
		TEXT("+1"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		10, 40,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON31,
		hInstance,
		NULL);
	hwndButton = CreateWindow(TEXT("button"),
		TEXT(">"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		40, 40,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON34,
		hInstance,
		NULL);
	//################# 2 pietro  ############################

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("1"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		1100, 485,                                  // the left and top co-ordinates
		29, 29,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON16,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),
		TEXT("3"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		1100, 455,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON17,
		hInstance,
		NULL);
	hwndButton = CreateWindow(TEXT("button"),
		TEXT("4"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		1100, 425,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON18,
		hInstance,
		NULL);
	hwndButton = CreateWindow(TEXT("button"),
		TEXT("5"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		1100, 395,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON19,
		hInstance,
		NULL);
	hwndButton = CreateWindow(TEXT("button"),
		TEXT("W"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		1100, 365,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON20,
		hInstance,
		NULL);
	hwndButton = CreateWindow(TEXT("button"),
		TEXT("+1"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		1100, 335,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON28,
		hInstance,
		NULL);
	hwndButton = CreateWindow(TEXT("button"),
		TEXT(">"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		1070, 335,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON35,
		hInstance,
		NULL);
	//################# 4 pietro  ############################

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("1"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		1100, 280,                                  // the left and top co-ordinates
		29, 29,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON21,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),
		TEXT("2"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		1100, 250,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON22,
		hInstance,
		NULL);
	hwndButton = CreateWindow(TEXT("button"),
		TEXT("3"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		1100, 220,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON23,
		hInstance,
		NULL);
	hwndButton = CreateWindow(TEXT("button"),
		TEXT("5"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		1100, 190,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON24,
		hInstance,
		NULL);
	hwndButton = CreateWindow(TEXT("button"),
		TEXT("W"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		1100, 160,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON25,
		hInstance,
		NULL);

	hwndButton = CreateWindow(TEXT("button"), //Ludzik
		TEXT("+1"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		1100, 130,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON30,
		hInstance,
		NULL);
	hwndButton = CreateWindow(TEXT("button"),
		TEXT(">"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		1070, 130,
		29, 29,
		hWnd,
		(HMENU)ID_BUTTON36,
		hInstance,
		NULL);
	
	OnCreate(hWnd);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);

		// MENU & BUTTON messages
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case ID_BUTTON1:
			if (pietro == 1) {

				if (if_going == false) {
					elevator.how_many2++;
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				else {
					pietro = 2;
					a = 115;
					while (a != 0) {
						draw_people = 7;
						repaintWindow(hWnd, hdc, ps, &drawArea1);
						Sleep(5);
						a--;
					}
					Sleep(50);
					elevator.people_at_elevator = elevator.people_at_elevator - elevator.how_many2;
					elevator.how_many2 = 0;
					draw_people = 0;
					repaintWindow(hWnd, hdc, ps, &drawArea6);
					repaintWindow(hWnd, hdc, ps, NULL);
					if_going = false;
				}
			}
			break;
		case ID_BUTTON2:
			if (pietro == 1) {
				if (if_going == false) {
					elevator.how_many3++;
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				else {
					pietro = 3;
					a = 205;
					while (a != 0) {
						repaintWindow(hWnd, hdc, ps, &drawArea1);
						draw_people = 8;
						Sleep(5);
						a--;
					}
					Sleep(50);
					elevator.people_at_elevator = elevator.people_at_elevator - elevator.how_many3;
					elevator.how_many3 = 0;
					draw_people = 0;
					repaintWindow(hWnd, hdc, ps, &drawArea3);
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				if_going = false;
			}
			break;
		case ID_BUTTON3:
			if (pietro == 1) {
				if (if_going == false) {
					elevator.how_many4++;
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				else {
					pietro = 4;
					a = 320;
					while (a != 0) {
						draw_people = 9;
						repaintWindow(hWnd, hdc, ps, &drawArea1);
						Sleep(5);
						a--;
					}
					Sleep(50);
					elevator.people_at_elevator = elevator.people_at_elevator - elevator.how_many4;
					elevator.how_many4 = 0;
					draw_people = 0;
					repaintWindow(hWnd, hdc, ps, &drawArea5);
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				if_going = false;
			}
			break;
		case ID_BUTTON4:
			if (pietro == 1) {
				if (if_going == false) {
					elevator.how_many5++;
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				else {
					pietro = 5;
					a = 410;
					while (a != 0) {
						draw_people = 10;
						repaintWindow(hWnd, hdc, ps, &drawArea1);
						Sleep(5);
						a--;
					}
					Sleep(50);
					elevator.people_at_elevator = elevator.people_at_elevator - elevator.how_many5;
					elevator.how_many5 = 0;
					draw_people = 0;
					repaintWindow(hWnd, hdc, ps, &drawArea2);
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				if_going = false;
			}
			break;
		case ID_BUTTON5:
			if (pietro == 2) a = -115;
			if (pietro == 3) a = -205;
			if (pietro == 4) a = -320;
			if (pietro == 5) a = -410;
			pietro = 1;

			while (a != 0) {
				repaintWindow(hWnd, hdc, ps, &drawArea1);
				Sleep(5);
				a++;
			}
			Sleep(50);
			draw_people = 0;
			repaintWindow(hWnd, hdc, ps, &drawArea4);
			break;
		case ID_BUTTON32:
			if (pietro == 1) {
				elevator.waiting_people = elevator.how_many2 + elevator.how_many3 + elevator.how_many4 + elevator.how_many5 - elevator.people_at_elevator;
				for (int i = 0; i < elevator.waiting_people; i++) {
					if (elevator.people_at_elevator < 8) {
						elevator.people_at_elevator++;
					}
				}
				elevator.waiting_people = elevator.waiting_people - elevator.people_at_elevator;
				if_going = true;
				draw_people = 6;
				repaintWindow(hWnd, hdc, ps, NULL);
			}
			break;
			//############# 3 pietro  ############
		case ID_BUTTON6:
			if (pietro == 3) {
				if (if_going == false) {
					elevator.how_many1++;
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				else {
					pietro = 1;
					a = -205;
					while (a != 0) {
						draw_people = 6;
						repaintWindow(hWnd, hdc, ps, &drawArea1);
						Sleep(5);
						a++;
					}
					Sleep(50);
					elevator.people_at_elevator = elevator.people_at_elevator - elevator.how_many1;
					elevator.how_many1 = 0;
					draw_people = 0;
					repaintWindow(hWnd, hdc, ps, &drawArea4);
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				if_going = false;
			}

			break;
		case ID_BUTTON7:
			if (pietro == 3) {
				if (if_going == false) {
					elevator.how_many2++;
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				else {
					pietro = 2;
					a = -90;
					while (a != 0) {
						draw_people = 7;
						repaintWindow(hWnd, hdc, ps, &drawArea1);
						Sleep(5);
						a++;
					}
					Sleep(50);
					elevator.people_at_elevator = elevator.people_at_elevator - elevator.how_many2;
					elevator.how_many2 = 0;
					draw_people = 0;
					repaintWindow(hWnd, hdc, ps, &drawArea6);
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				if_going = false;
			}
			break;
		case ID_BUTTON8:
			if (pietro == 3) {
				if (if_going == false) {
					elevator.how_many4++;
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				else {
					pietro = 4;
					a = 115;
					while (a != 0) {
						draw_people = 9;
						repaintWindow(hWnd, hdc, ps, &drawArea1);
						Sleep(5);
						a--;
					}
					Sleep(50);
					elevator.people_at_elevator = elevator.people_at_elevator - elevator.how_many4;
					elevator.how_many4 = 0;
					draw_people = 0;
					repaintWindow(hWnd, hdc, ps, &drawArea5);
					repaintWindow(hWnd, hdc, ps, NULL);
				}

				if_going = false;
			}
			break;
		case ID_BUTTON9:
			if (pietro == 3) {
				if (if_going == false) {

					elevator.how_many5++;
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				else {
					pietro = 5;
					a = 205;
					while (a != 0) {
						draw_people = 10;
						repaintWindow(hWnd, hdc, ps, &drawArea1);
						Sleep(5);
						a--;
					}
					Sleep(50);
					elevator.people_at_elevator = elevator.people_at_elevator - elevator.how_many5;
					elevator.how_many5 = 0;
					draw_people = 0;
					repaintWindow(hWnd, hdc, ps, &drawArea2);
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				if_going = false;
			}
			break;
		case ID_BUTTON10:

			if (pietro == 1) a = 205;
			if (pietro == 2) a = 90;
			if (pietro == 4) a = -115;
			if (pietro == 5) a = -205;
			pietro = 3;
			while (a != 0) {
				repaintWindow(hWnd, hdc, ps, &drawArea1);
				Sleep(5);
				if (a < 0) {
					a++;
				}
				else
				{
					a--;
				}
			}
			Sleep(50);
			draw_people = 0;
			repaintWindow(hWnd, hdc, ps, &drawArea3);
			break;
		case ID_BUTTON33:
			if (pietro == 3) {
				elevator.waiting_people = elevator.how_many1 + elevator.how_many2 + elevator.how_many4 + elevator.how_many5 - elevator.people_at_elevator;
				for (int i = 0; i < elevator.waiting_people; i++) {
					if (elevator.people_at_elevator < 8) {
						elevator.people_at_elevator++;
					}
				}
				elevator.waiting_people = elevator.waiting_people - elevator.people_at_elevator;
				if_going = true;
				draw_people = 8;
				repaintWindow(hWnd, hdc, ps, NULL);
			}
			break;
			//############ 5 pietro  #############

		case ID_BUTTON11:
			if (pietro == 5) {
				if (if_going == false) {
					elevator.how_many1++;
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				else {
					pietro = 1;
					a = -410;
					while (a != 0) {
						draw_people = 6;
						repaintWindow(hWnd, hdc, ps, &drawArea1);
						Sleep(5);
						a++;
					}
					Sleep(50);
					elevator.people_at_elevator = elevator.people_at_elevator - elevator.how_many1;
					elevator.how_many1 = 0;
					draw_people = 0;
					repaintWindow(hWnd, hdc, ps, &drawArea4);
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				if_going = false;
			}
			break;
		case ID_BUTTON12:
			if (pietro == 5) {
				if (if_going == false) {
					elevator.how_many2++;
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				else {
					pietro = 2;
					a = -295;
					while (a != 0) {
						draw_people = 7;
						repaintWindow(hWnd, hdc, ps, &drawArea1);
						Sleep(5);
						a++;
					}
					Sleep(50);
					elevator.people_at_elevator = elevator.people_at_elevator - elevator.how_many2;
					elevator.how_many2 = 0;
					draw_people = 0;
					repaintWindow(hWnd, hdc, ps, &drawArea6);
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				if_going = false;
			}
			break;
		case ID_BUTTON13:
			if (pietro == 5) {
				if (if_going == false) {
					elevator.how_many3++;
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				else {
					pietro = 3;
					a = -205;
					while (a != 0) {
						draw_people = 8;
						repaintWindow(hWnd, hdc, ps, &drawArea1);
						Sleep(5);
						a++;
					}
					Sleep(50);
					elevator.people_at_elevator = elevator.people_at_elevator - elevator.how_many3;
					elevator.how_many3 = 0;
					draw_people = 0;
					repaintWindow(hWnd, hdc, ps, &drawArea3);
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				if_going = false;
			}
			break;
		case ID_BUTTON14:
			if (pietro == 5) {
				if (if_going == false) {
					elevator.how_many4++;
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				else {
					pietro = 4;
					a = -90;
					while (a != 0) {
						draw_people = 9;
						repaintWindow(hWnd, hdc, ps, &drawArea1);
						Sleep(5);
						a++;
					}
					Sleep(50);
					elevator.people_at_elevator = elevator.people_at_elevator - elevator.how_many4;
					elevator.how_many4 = 0;
					draw_people = 0;
					repaintWindow(hWnd, hdc, ps, &drawArea5);
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				if_going = false;
			}
			break;
		case ID_BUTTON15:
			if (pietro == 1) a = 410;
			if (pietro == 2) a = 295;
			if (pietro == 3) a = 205;
			if (pietro == 4) a = 90;
			pietro = 5;

			while (a != 0) {
				repaintWindow(hWnd, hdc, ps, &drawArea1);
				Sleep(5);
				a--;
			}
			Sleep(50);
			draw_people = 0;
			repaintWindow(hWnd, hdc, ps, &drawArea2);
			break;
		case ID_BUTTON34:
			if (pietro == 5) {
				elevator.waiting_people = elevator.how_many1 + elevator.how_many2 + elevator.how_many3 + elevator.how_many4 - elevator.people_at_elevator;
				for (int i = 0; i < elevator.waiting_people; i++) {
					if (elevator.people_at_elevator < 8) {
						elevator.people_at_elevator++;
					}
				}
				elevator.waiting_people = elevator.waiting_people - elevator.people_at_elevator;
				if_going = true;
				draw_people = 10;
				repaintWindow(hWnd, hdc, ps, NULL);
			}
			break;
			//################ 2 pietro  ##################
		case ID_BUTTON16:
			if (pietro == 2) {
				if (if_going == false) {
					elevator.how_many1++;
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				else {
					pietro = 1;
					a = -115;
					while (a != 0) {
						draw_people = 6;
						repaintWindow(hWnd, hdc, ps, &drawArea1);
						Sleep(5);
						a++;
					}
					Sleep(50);
					elevator.people_at_elevator = elevator.people_at_elevator - elevator.how_many1;
					elevator.how_many1 = 0;
					draw_people = 0;
					repaintWindow(hWnd, hdc, ps, &drawArea4);
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				if_going = false;
			}
			break;
		case ID_BUTTON17:
			if (pietro == 2) {
				if (if_going == false) {
					elevator.how_many3++;
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				else {
					pietro = 3;
					a = 90;
					while (a != 0) {
						draw_people = 8;
						repaintWindow(hWnd, hdc, ps, &drawArea1);
						Sleep(5);
						a--;
					}
					Sleep(50);
					elevator.people_at_elevator = elevator.people_at_elevator - elevator.how_many3;
					elevator.how_many3 = 0;
					draw_people = 0;
					repaintWindow(hWnd, hdc, ps, &drawArea3);
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				if_going = false;
			}
			break;
		case ID_BUTTON18:
			if (pietro == 2) {
				if (if_going == false) {
					elevator.how_many4++;
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				else {
					pietro = 4;
					a = 205;
					while (a != 0) {
						draw_people = 9;
						repaintWindow(hWnd, hdc, ps, &drawArea1);
						Sleep(5);
						a--;
					}
					Sleep(50);
					elevator.people_at_elevator = elevator.people_at_elevator - elevator.how_many4;
					elevator.how_many4 = 0;
					draw_people = 0;
					repaintWindow(hWnd, hdc, ps, &drawArea5);
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				if_going = false;
			}
			break;
		case ID_BUTTON19:
			if (pietro == 2) {
				if (if_going == false) {
					elevator.how_many5++;
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				else {
					pietro = 5;
					a = 295;
					while (a != 0) {
						draw_people = 10;
						repaintWindow(hWnd, hdc, ps, &drawArea1);
						Sleep(5);
						a--;
					}
					Sleep(50);
					elevator.people_at_elevator = elevator.people_at_elevator - elevator.how_many5;
					elevator.how_many5 = 0;
					draw_people = 0;
					repaintWindow(hWnd, hdc, ps, &drawArea2);
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				if_going = false;
			}
			break;
		case ID_BUTTON20:
			if (pietro == 1) a = 115;
			if (pietro == 3) a = -90;
			if (pietro == 4) a = -205;
			if (pietro == 5) a = -295;
			pietro = 2;

			while (a != 0) {
				repaintWindow(hWnd, hdc, ps, &drawArea1);
				Sleep(5);
				if (a < 0) {
					a++;
				}
				else
				{
					a--;
				}

			}
			Sleep(50);
			draw_people = 0;
			repaintWindow(hWnd, hdc, ps, &drawArea6);
			break;
		case ID_BUTTON35:
			if (pietro == 2) {
				elevator.waiting_people = elevator.how_many1 + elevator.how_many3 + elevator.how_many4 + elevator.how_many5 - elevator.people_at_elevator;
				for (int i = 0; i < elevator.waiting_people; i++) {
					if (elevator.people_at_elevator < 8) {
						elevator.people_at_elevator++;
					}
				}
				elevator.waiting_people = elevator.waiting_people - elevator.people_at_elevator;
				if_going = true;
				draw_people = 7;
				repaintWindow(hWnd, hdc, ps, NULL);
			}
			break;
			//########## 4 pietro  #########
		case ID_BUTTON21:
			if (pietro == 4) {
				if (if_going == false) {
					elevator.how_many1++;
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				else {
					pietro = 1;
					a = -320;
					while (a != 0) {
						draw_people = 6;
						repaintWindow(hWnd, hdc, ps, &drawArea1);
						Sleep(5);
						a++;
					}
					Sleep(50);
					elevator.people_at_elevator = elevator.people_at_elevator - elevator.how_many1;
					elevator.how_many1 = 0;
					draw_people = 0;
					repaintWindow(hWnd, hdc, ps, &drawArea4);
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				if_going = false;
			}
			break;
		case ID_BUTTON22:
			if (pietro == 4) {
				if (if_going == false) {
					elevator.how_many2++;
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				else {
					pietro = 2;
					a = -205;
					while (a != 0) {
						draw_people = 7;
						repaintWindow(hWnd, hdc, ps, &drawArea1);
						Sleep(5);
						a++;
					}
					Sleep(50);
					elevator.people_at_elevator = elevator.people_at_elevator - elevator.how_many2;
					elevator.how_many2 = 0;
					draw_people = 0;
					repaintWindow(hWnd, hdc, ps, &drawArea6);
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				if_going = false;
			}
			break;
		case ID_BUTTON23:
			if (pietro == 4) {
				if (if_going == false) {
					elevator.how_many3++;
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				else {
					pietro = 3;
					a = -115;
					while (a != 0) {
						draw_people = 8;
						repaintWindow(hWnd, hdc, ps, &drawArea1);
						Sleep(5);
						a++;
					}
					Sleep(50);
					elevator.people_at_elevator = elevator.people_at_elevator - elevator.how_many3;
					elevator.how_many3 = 0;
					draw_people = 0;
					repaintWindow(hWnd, hdc, ps, &drawArea3);
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				if_going = false;
			}
			break;
		case ID_BUTTON24:
			if (pietro == 4) {
				if (if_going == false) {
					elevator.how_many5++;
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				else {
					pietro = 5;
					a = 90;
					while (a != 0) {
						draw_people = 10;
						repaintWindow(hWnd, hdc, ps, &drawArea1);
						Sleep(5);
						a--;
					}
					Sleep(50);
					elevator.people_at_elevator = elevator.people_at_elevator - elevator.how_many5;
					elevator.how_many5 = 0;
					draw_people = 0;
					repaintWindow(hWnd, hdc, ps, &drawArea2);
					repaintWindow(hWnd, hdc, ps, NULL);
				}
				if_going = false;
			}
			break;
		case ID_BUTTON25:
			if (pietro == 1) a = 320;
			if (pietro == 2) a = 205;
			if (pietro == 3) a = 115;
			if (pietro == 5) a = -90;
			pietro = 4;
			while (a != 0) {
				repaintWindow(hWnd, hdc, ps, &drawArea1);
				Sleep(5);
				if (a < 0) {
					a++;
				}
				else
				{
					a--;
				}

			}
			Sleep(50);
			draw_people = 0;
			repaintWindow(hWnd, hdc, ps, &drawArea5);
			break;
		case ID_BUTTON36:
			if (pietro == 4) {
				elevator.waiting_people = elevator.how_many1 + elevator.how_many2 + elevator.how_many3 + elevator.how_many5 - elevator.people_at_elevator;
				for (int i = 0; i < elevator.waiting_people; i++) {
					if (elevator.people_at_elevator < 8) {
						elevator.people_at_elevator++;
					}
				}
				elevator.waiting_people = elevator.waiting_people - elevator.people_at_elevator;
				if_going = true;
				draw_people = 9;
				repaintWindow(hWnd, hdc, ps, NULL);
			}
			break;
		case ID_BUTTON26:
			draw_people = 3;
			repaintWindow(hWnd, hdc, ps, &drawArea3);
			break;
		case ID_BUTTON28:
			draw_people = 2;
			repaintWindow(hWnd, hdc, ps, &drawArea6);
			break;
		case ID_BUTTON29:
			draw_people = 1;
			repaintWindow(hWnd, hdc, ps, &drawArea4);
			break;
		case ID_BUTTON30:
			draw_people = 4;
			repaintWindow(hWnd, hdc, ps, &drawArea5);
			break;
		case ID_BUTTON31:
			draw_people = 5;
			repaintWindow(hWnd, hdc, ps, &drawArea2);
			break;
		case ID_BUTTON99:
			repaintWindow(hWnd, hdc, ps, NULL);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here (not depend on timer, buttons)
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
