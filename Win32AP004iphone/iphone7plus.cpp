/*---------------------------------------------
Iphone7plus.cpp
-----------------------------------------------*/

#define _USE_MATH_DEFINES
#include <windows.h>
#include <tchar.h>
#include <math.h>

// �v���g�^�C�v�錾
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// ���ϐ�
static TCHAR szWindowClass[] = _T("iPhone7Plus");
static TCHAR szTitle[] = _T("iPhone7Plus");
HINSTANCE	hInst;

int window_pos_x = 100;
int window_pos_y = 100;
int window_width = 350;
int window_height = 690;

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR pCmdLine,
	int nCmdShow) {

	WNDCLASSEX wcex;

	// �E�B���h�E�N���X�̏���ݒ�
	wcex.cbSize = sizeof(WNDCLASSEX);				// �\���̃T�C�Y
	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;	// �X�^�C��
	wcex.lpfnWndProc = WndProc;							// �E�B���h�E�v���V�[�W��
	wcex.cbClsExtra = 0;									// �g�����P
	wcex.cbWndExtra = 0;									// �g�����Q
	wcex.hInstance = hInstance;							// �C���X�^���X�n���h��
	wcex.hIcon = (HICON)LoadImage(					// �A�C�R��
		NULL,
		MAKEINTRESOURCE(IDI_APPLICATION),
		IMAGE_ICON,
		0,
		0,
		LR_DEFAULTSIZE | LR_SHARED
		);
	wcex.hIconSm = wcex.hIcon;							// �q�A�C�R��
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;							// ���j���[��
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	// �E�B���h�E�N���X��o�^����
	if (!RegisterClassEx(&wcex)) {
		MessageBox(NULL,
			_T("�E�B���h�E�̓o�^�Ɏ��s���܂���"),
			_T("�E�B���h�E�̓o�^�G���["),
			NULL);
		return 1;
	}

	hInst = hInstance; // �C���X�^���X��n���h������ϐ��Ɋi�[

	// �E�B���h�E���쐬����
	HWND hWnd = CreateWindow(
		szWindowClass,					// �E�B���h�E�N���X��
		szTitle,							// �^�C�g���o�[�ɕ\�����镶����
		WS_OVERLAPPEDWINDOW,		// �E�B���h�E�̎��
		window_pos_x,								// �E�B���h�E��\������ʒu(X���W)
		window_pos_y,								// �E�B���h�E��\������ʒu(Y���W)
	    window_width,								// �E�B���h�E�̕�
		window_height,								// �E�B���h�E�̍���
		NULL,							// �e�E�B���h�E�̃E�B���h�E�n���h��
		NULL,							// ���j���[�n���h��
		hInst,							// �C���X�^���X�n���h��
		NULL							// ���̑��̍쐬�f�[�^
		);

	if (!hWnd) {
		MessageBox(NULL,
			_T("�E�B���h�E�̍쐬�Ɏ��s���܂���"),
			_T("�E�B���h�E�̍쐬�G���["),
			NULL);
		return 1;
	}

	// �E�B���h�E��\������
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// ���b�Z�[�W����[�v
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

// �E�B���h�E�v���V�[�W��
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	HDC hDC;
	HBRUSH  hBrushBlack;
	HBRUSH  hBrushYellow;
	HBRUSH  hBrushWhite;
	PAINTSTRUCT ps;
	LPCTSTR STR1 = _T("i");
	LPCTSTR STR2 = _T("n");
	LPCTSTR STR3 = _T("f");
	LPCTSTR STR4 = _T("i");
	LPCTSTR STR5 = _T("n");
	LPCTSTR STR6 = _T("i");
	LPCTSTR STR7 = _T("t");
	LPCTSTR STR8 = _T("y");
	 //LPCTSTR STR = _T("y");
	//WCHAR c[9] = _T("infinity");
	//int numChar;  //STR�̕�����
	//int *pDx;     //�����̊Ԋu��\���z��
	static LOGFONT logfont;  //�t�H���g���̍\����
	HFONT hFont;
	int angle;

	switch (message) {
	case WM_CREATE:
		ZeroMemory(&logfont, sizeof(logfont));	// �t�H���g���\���̂��O�ŏ�����
		logfont.lfCharSet = DEFAULT_CHARSET;	// �V�X�e���̃f�t�H���g�����Z�b�g���g��
		//logfont.lfHeight = 700;
		wsprintf(logfont.lfFaceName, _T("Times New Roman"));
		break;
		
	case WM_PAINT:{

					  hDC = BeginPaint(hWnd, &ps);		// GDI�֐��ɂ��`����J�n����
					  hFont = CreateFontIndirect(&logfont);
					  SelectObject(hDC, hFont);

					  hBrushBlack = CreateSolidBrush(RGB(0, 0, 0));
					  SelectObject(hDC, hBrushBlack);
					  RoundRect(hDC, 10, 10, 322, 643, 70, 80);    //iPhone7�̊O�g
					  Rectangle(hDC, 7, 85, 20, 110);               //�}�i�[���[�hON/OFF�L�[
					  Rectangle(hDC, 7, 135, 20, 185);               //���ʁ{�{�^��
					  Rectangle(hDC, 7, 200, 20, 250);               //���ʁ|�{�^��
					  Rectangle(hDC, 321, 120, 325, 170);               //�d���{�^��

					  hBrushWhite = CreateSolidBrush(RGB(255, 255, 255));
					  SelectObject(hDC, hBrushWhite);
					  Ellipse(hDC, 162, 25, 170, 33);              //�����㕔�̊�
					  Ellipse(hDC, 100, 35, 115, 50);              //�����㕔���̊�
					  RoundRect(hDC, 129, 39, 207, 46, 10, 80);
					  Ellipse(hDC, 139, 579, 193, 633);            //�{�^���̊O��

					  hBrushYellow = CreateSolidBrush(RGB(255, 255, 0));
					  SelectObject(hDC, hBrushYellow);
					  Rectangle(hDC, 29, 83, 303, 569);            //iPhone7�̉�ʃT�C�Y

					  /*������`��*/
					  double x0 = 170;
					  double y0 = 310;
					  int i = 0;
					  //LPCTSTR STR = _T(c);
					  //logfont.lfWidth = 100;
					  //logfont.lfHeight = 100;
					  MoveToEx(hDC, x0, y0, NULL);     //�J�n�_�Ɉړ�
					  for (angle = -2; angle <= 3600; angle += 100){
						  for (double theta = 0; theta < 85; theta += 0.1){
							  i++;
							  double a1 = 1.09;
							  double x1 = pow(a1, theta)*cos(theta) + x0;       //x���W��ݒ�
							  double y1 = pow(a1, theta)*sin(theta) + y0;       //y���W��ݒ�
							  if ((x1 >= 20 && x1 <= 303) && (y1 >= 83 && y1 <= 555)){  //�O�g�̊O�͗����𔒂ŕ`��

								  //LineTo(hDC, x1, y1);            //�����_�̍��W����(x1, y1)�ɐ���`��
								  SetBkMode(hDC, TRANSPARENT);      //�e�L�X�g�̔w�i�𓧖��ɂ���
								  //SetBkColor(hDC, RGB(255, 255, 0));
								  logfont.lfOrientation = angle;

								  //logfont.lfWidth += theta;
								  //logfont.lfHeight += angle;
								  //for (i = 0; i < 9; i++){
									  //LPCTSTR STR = (LPCTSTR)c[i];
								  while(i < 9){
									  switch (i){
									  case 1:
										  TextOut(hDC, x1, y1, STR1, _tcslen(STR1));
										  //i++;
										  break;
									  case 2:
										  TextOut(hDC, x1, y1, STR2, _tcslen(STR2));
										  //i++;
										  break;
									  case 3:
										  TextOut(hDC, x1, y1, STR3, _tcslen(STR3));
										  //i++;
										  break;
									  case 4:
										  TextOut(hDC, x1, y1, STR4, _tcslen(STR4));
										  //i++;
										  break;
									  case 5:
										  TextOut(hDC, x1, y1, STR5, _tcslen(STR5));
										  //i++;
										  break;
									  case 6:
										  TextOut(hDC, x1, y1, STR6, _tcslen(STR6));
										  //i++;
										  break;
									  case 7:
										  TextOut(hDC, x1, y1, STR7, _tcslen(STR7));
										  //i++;
										  break;
									  case 8:
										  TextOut(hDC, x1, y1, STR8, _tcslen(STR8));
										  i = 0;
										  break;
									  }
									  
									  break;
								  }
								  //i++;
								  
									  //TextOut(hDC, x1, y1, STR, _tcslen(STR));
									  /*if (i == 8){
										  i = 0;
									  }*/
								  //}
								  //i = 0;
								  DeleteObject(hFont); 					// �쐬�����_���t�H���g���폜����
								  /*i++;
								  if (i == 8){
									  i = 0;
								  }*/

							  }

						  }
					  }

					  SelectObject(hDC, hBrushBlack);
					  Ellipse(hDC, 144, 584, 188, 628);            //�{�^���̓���


					  EndPaint(hWnd, &ps);				// GDI�֐��ɂ��`����I������
	}break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}
