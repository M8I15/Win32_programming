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
		100,								// �E�B���h�E��\������ʒu(X���W)
		100,								// �E�B���h�E��\������ʒu(Y���W)
	    350,								// �E�B���h�E�̕�
		700,								// �E�B���h�E�̍���
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

	switch (message) {
	case WM_PAINT:{

					  hDC = BeginPaint(hWnd, &ps);		// GDI�֐��ɂ��`����J�n����

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
					  //MoveToEx(hDC, 137, 243, NULL);     //�J�n�_�Ɉړ�
					  //for (int theta = 0; theta < 360; theta += 10){
					  double x0 = 137.0;
					  double y0 = 243.0;
					  for (double a2 = 0; a2 < 30; a2 += 0.1){
						  //MoveToEx(hDC, x0, y0, NULL);     //�J�n�_�Ɉړ�
						  //double rad = theta / 180 * M_PI;
						  double a1 = 1.2;
						  double x1 = pow(a1, a2*cos(a2))*-1 + 200;
						  double y1 = pow(a1, a2*sin(a2)) + 350;
						  //SetPixel(hDC, x, y, 0xFF);
						  LineTo(hDC, x1, y1);            //����`��

						  //x0 = x1;
						  //y0 = y1;
					  }
					  //}

					  hBrushBlack = CreateSolidBrush(RGB(0, 0, 0));
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
