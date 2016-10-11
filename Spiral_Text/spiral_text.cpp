/*---------------------------------------------
spiral_text.cpp
-----------------------------------------------*/

#define _USE_MATH_DEFINES
#include <windows.h>
#include <tchar.h>
#include <math.h>

// プロトタイプ宣言
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// 大域変数
static TCHAR szWindowClass[] = _T("spiral_text");
static TCHAR szTitle[] = _T("spiral_text");
HINSTANCE	hInst;
int width, height;

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR pCmdLine,
	int nCmdShow) {

	WNDCLASSEX wcex;

	// ウィンドウクラスの情報を設定
	wcex.cbSize = sizeof(WNDCLASSEX);				// 構造体サイズ
	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;	// スタイル
	wcex.lpfnWndProc = WndProc;							// ウィンドウプロシージャ
	wcex.cbClsExtra = 0;									// 拡張情報１
	wcex.cbWndExtra = 0;									// 拡張情報２
	wcex.hInstance = hInstance;							// インスタンスハンドル
	wcex.hIcon = (HICON)LoadImage(					// アイコン
		NULL,
		MAKEINTRESOURCE(IDI_APPLICATION),
		IMAGE_ICON,
		0,
		0,
		LR_DEFAULTSIZE | LR_SHARED
		);
	wcex.hIconSm = wcex.hIcon;							// 子アイコン
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;							// メニュー名
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	// ウィンドウクラスを登録する
	if (!RegisterClassEx(&wcex)) {
		MessageBox(NULL,
			_T("ウィンドウの登録に失敗しました"),
			_T("ウィンドウの登録エラー"),
			NULL);
		return 1;
	}

	hInst = hInstance; // インスタンス･ハンドルを大域変数に格納

	// ウィンドウを作成する
	HWND hWnd = CreateWindow(
		szWindowClass,					// ウィンドウクラス名
		szTitle,							// タイトルバーに表示する文字列
		WS_OVERLAPPEDWINDOW,		// ウィンドウの種類
		CW_USEDEFAULT,				// ウィンドウを表示する位置(X座標）
		CW_USEDEFAULT,				// ウィンドウを表示する位置(Y座標）
		width = CW_USEDEFAULT,				// ウィンドウの幅
		height = CW_USEDEFAULT,				// ウィンドウの高さ
		NULL,							// 親ウィンドウのウィンドウハンドル
		NULL,							// メニューハンドル
		hInst,							// インスタンスハンドル
		NULL							// その他の作成データ
		);

	if (!hWnd) {
		MessageBox(NULL,
			_T("ウィンドウの作成に失敗しました"),
			_T("ウィンドウの作成エラー"),
			NULL);
		return 1;
	}

	// ウィンドウを表示する
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// メッセージ･ループ
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

// ウィンドウプロシージャ
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	static LPCTSTR TEST_STR = _T("infinity");
	static LOGFONT logfont;	// フォント情報の構造体
	HDC hDC;
	HFONT hFont;
	double angle;
	float radius = 10;
	int centx = width / 2;
	int centy = height / 2;
	int i = 0;

	switch (message) {
	case WM_CREATE:			// ウィンドウが作成されたとき
		ZeroMemory(&logfont, sizeof(logfont));	// フォント情報構造体を０で初期化
		logfont.lfCharSet = DEFAULT_CHARSET;	// システムのデフォルト文字セットを使う
		//logfont.lfWeight = 700;
		wsprintf(logfont.lfFaceName, _T("Times New Roman"));
		break;

	case WM_LBUTTONDOWN:	// マウスの左ボタンが押されたとき
		hDC = GetDC(hWnd);
		int i;
		double j,x,y,r;
		i = 0;

		for (angle = 0; angle <= 360; angle += 10) {
			//len = (int)(angle*3+5);
			for (j = 1; j<5; j += 0.5)
			{
				r = pow(j,angle);
				x = r*cos(angle)+200;
				y = r*sin(angle)+200;
				SetPixel(hDC, (int)x, (int)y, RGB(255, 0, 0));  // 点を打つ
			}
			//float rad = angle*M_PI / 180;
			//float x = centx + (radius * cos(rad));
			//float y = centy + (radius * sin(rad));
			//float r = exp(angle);
			//Ellipse(hDC, angle, angle, angle+100, angle+100);
			//radius += 0.5;
			hFont = CreateFontIndirect(&logfont); 	// 論理フォントを作成する
			SelectObject(hDC, hFont);
			logfont.lfOrientation = 200;
			TextOut(
				hDC,
				LOWORD(lParam),
				HIWORD(lParam),
				TEST_STR,
				(int)_tcslen(TEST_STR));
			DeleteObject(hFont); // 作成した論理フォントを削除する

			//i++;
		}
		ReleaseDC(hWnd, hDC);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}
