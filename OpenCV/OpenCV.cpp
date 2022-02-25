// OpenCV.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#ifdef _DEBUG
#pragma comment(lib, "opencv_world455d.lib")
#else
#pragma comment(lib, "opencv_world455.lib")
#endif

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	//項目選択処理用変数
	int mode;

	//フォーマット指定用変数
	int format;

	//トリミングサイズ指定用変数
	int x, y, w, h;

	//回転角度指定用変数
	int rotate;

	//パス用変数
	char path[1000];

	//文字描画変数
	char s[1000];
	int x2, y2;

	cv::Mat img;


	printf("画像のパスを入力する\n");
	//パスの入力
	(void)scanf("%s", path);

	//画像を読み込む
	img = cv::imread(path);
	

	//エラー処理
	if (img.empty() == true) 
	{
		// 画像の中身が空なら終了する
		return 0;
	}
	
	//項目一覧の表示
	printf("0:画像を表示する\n");
	printf("1:白黒加工する\n");
	printf("2:トリミングする\n");
	printf("3:反転する\n");
	printf("4:モザイク処理する\n");
	printf("5:画像を回転させる\n");
	printf("6:文字を入れる\n");
	printf("7:図形を描画する\n");
	printf("8:画像サイズの変更\n");
	printf("10:画像を保存する\n");
	printf("11:違う画像を読み込む\n");
	printf("99:終了する\n");

	(void)scanf("%d", &mode);

	while (mode != 0 &&
		mode != 1 &&
		mode != 2 &&
		mode != 3 &&
		mode != 4 &&
		mode != 5 &&
		mode != 6 &&
		mode != 7 &&
		mode != 8 &&
		mode != 10 &&
		mode != 11 &&
		mode != 99)
	{
		//エラーメッセージ
		printf("一覧の中から選んでください\n\n");

		//項目一覧の表示
		printf("0:画像を表示する\n");
		printf("1:白黒加工する\n");
		printf("2:トリミングする\n");
		printf("3:反転する\n");
		printf("4:モザイク処理する\n");
		printf("5:画像を回転させる\n");
		printf("6:文字を入れる\n");
		printf("7:図形を描画する\n");
		printf("8:画像サイズの変更\n");
		printf("10:画像を保存する\n");
		printf("11:違う画像を読み込む\n");
		printf("99:終了する\n");

		(void)scanf("%d", &mode);
	}

	//終了するまでループ
	while (mode != 99) 
	{
		//0を入力した場合
		if (mode == 0) 
		{
			//画像を表示する
			cv::imshow("title", img);
			cv::waitKey(0);
		}

		//1を入力した場合
		else if (mode == 1) 
		{
			//白黒加工する
			cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);

			printf("グレースケール化されました\n");
		}

		//2を入力した場合
		else if (mode == 2) 
		{
			//x座標を決める
			printf("x座標を入力する\n");
			(void)scanf("%d",&x);

			//y座標を決める
			printf("y座標を入力する\n");
			(void)scanf("%d", &y);

			//画像の横幅を決める
			printf("画像の横幅を入力する\n");
			(void)scanf("%d", &w);

			//画像の縦幅を決める
			printf("画像の縦幅を入力する\n");
			(void)scanf("%d", &h);

			//トリミングをする
			img = cv::Mat(img, cv::Rect(x,y,w,h));

			printf("トリミングされました\n");
		}

		//3を入力した場合
		else if (mode == 3) 
		{
			int n;

			//項目一覧の表示
			printf("0:上下反転\n");
			printf("1:左右反転\n");
			printf("-1:上下左右反転\n");

			(void)scanf("%d", &n);

			while (n < -1 || n > 1) 
			{
				//エラーメッセージ
				printf("一覧の中から選んでください\n\n");

				//項目一覧の表示
				printf("0:上下反転\n");
				printf("1:左右反転\n");
				printf("-1:上下左右反転\n");

				(void)scanf("%d", &n);
			}

			if (n == 0) 
			{
				//上下反転
				cv::flip(img, img, 0);

				printf("上下反転されました\n");
			}
			else if (n == 1)
			{
				//左右反転
				cv::flip(img, img, 1);

				printf("左右反転されました\n");
			}
			else if (n == -1)
			{
				//上下左右反転
				cv::flip(img, img, -1);

				printf("上下左右反転されました\n");
			}
		}

		//4を入力した場合
		else if (mode == 4)
		{
			int n = 8; // 閾値

			// 画像を縮小
			cv::resize(img, img, cv::Size(), (double)1 / n, (double)1 / n);

			// 画像を拡大
			cv::resize(img, img, cv::Size(), n, n, cv::INTER_NEAREST);

			printf("モザイク処理しました\n");
		}

		//5を入力した場合
		else if (mode == 5)
		{
			//項目一覧の表示
			printf("1:90度回転\n");
			printf("2:180度回転\n");
			printf("3:270度回転\n");

			//回転する角度を決める
			(void)scanf("%d", &rotate);
			
			//正しく入力されるまで再入力
			while (rotate < 1 || rotate > 3)
			{
				//エラーメッセージ
				printf("一覧の中から選んでください\n\n");

				//項目一覧の表示
				printf("1:90度回転\n");
				printf("2:180度回転\n");
				printf("3:270度回転\n");

				//回転する角度を決める
				(void)scanf("%d", &rotate);
			}

			if (rotate == 1)
			{
				//時計回りに90度回転
				cv::rotate(img, img, cv::ROTATE_90_CLOCKWISE);

				printf("画像が90度回転しましたn");
			}
			else if (rotate == 2)
			{
				//180度回転
				cv::rotate(img, img, cv::ROTATE_180);

				printf("画像が180度回転しました\n");
			}
			else if (rotate == 3)
			{
				//時計回りに270度回転
				cv::rotate(img, img, cv::ROTATE_90_COUNTERCLOCKWISE);

				printf("画像が270度回転しました\n");
			}
		}

		//6を入力した場合
		else if (mode == 6)
		{
			printf("入れたい文字を入力してください");

			scanf("%s", s);

			printf("文字列始点の左下座標のx座標");

			scanf("%d", &x2);

			printf("文字列始点の左下座標のy座標");

			scanf("%d", &y2);

			//文字の挿入
			cv::putText(
				img,
				s,
				cv::Point(x2, y2),
				cv::FONT_HERSHEY_SIMPLEX,
				1.5,
				cv::Scalar(0, 0, 0),
				2
			);

			printf("文字が挿入されました\n");
		}

		//7を入力した場合
		else if (mode == 7){

			int n;
			
			//項目一覧の表示
			printf("1:円の描画\n");
			printf("2:長方形の描画\n");

			scanf("%d", &n);

			if (n == 1) 
			{
				//円の描画

				int circlex, circley, size,color;
				
				printf("円を描く中心座標のx座標\n");
				scanf("%d", &circlex);

				printf("円を描く中心座標のy座標\n");
				scanf("%d", &circley);

				printf("円の半径(px)\n");
				scanf("%d", &size);

				printf("色を選択してください\n");

				//項目一覧の表示
				printf("1:黒\n");
				printf("2:赤\n");
				printf("3:緑\n");
				printf("4:青\n");

				scanf("%d", &color);

				while (color < 1 || color > 4) 
				{
					//エラーメッセージ
					printf("一覧の中から選んでください\n\n");

					//項目一覧の表示
					printf("1:黒\n");
					printf("2:赤\n");
					printf("3:緑\n");
					printf("4:青\n");

					(void)scanf("%d", &color);
				}

				if (color == 1) 
				{
					//黒い線で描画
					cv::circle(img, cv::Point(circlex, circley), size, cv::Scalar(0, 0, 0), 3);

					printf("描画されました\n");
				}
				else if (color == 2) 
				{
					//赤い線で描画
					cv::circle(img, cv::Point(circlex, circley), size, cv::Scalar(0, 0, 255), 3);

					printf("描画されました\n");
				}
				else if (color == 3) 
				{
					//緑の線で描画
					cv::circle(img, cv::Point(circlex, circley), size, cv::Scalar(0, 255, 0), 3);

					printf("描画されました\n");
				}
				else if (color == 4) 
				{
					//青の線で描画
					cv::circle(img, cv::Point(circlex, circley), size, cv::Scalar(255, 0, 0), 3);

					printf("描画されました\n");
				}
			}
			else if (n == 2) 
			{
				//長方形の描画

				int leftx, lefty, rightx, righty,color;

				printf("長方形の左上の座標のx座標");
				scanf("%d", &leftx);

				printf("長方形の左上の座標のy座標");
				scanf("%d", &lefty);

				printf("長方形の右下の座標のx座標");
				scanf("%d", &rightx);

				printf("長方形の右下の座標のy座標");
				scanf("%d", &righty);

				printf("色を選択してください\n");

				//項目一覧の表示
				printf("1:黒\n");
				printf("2:赤\n");
				printf("3:緑\n");
				printf("4:青\n");

				scanf("%d", &color);

				while (color < 1 || color > 4)
				{
					//エラーメッセージ
					printf("一覧の中から選んでください\n\n");

					//項目一覧の表示
					printf("1:黒\n");
					printf("2:赤\n");
					printf("3:緑\n");
					printf("4:青\n");

					scanf("%d", &color);
				}

				if (color == 1)
				{
					//黒い線で描画
					cv::rectangle(img, cv::Point(leftx, lefty), cv::Point(rightx, righty), cv::Scalar(0, 0, 0), 3);

					printf("描画されました\n");
				}
				else if (color == 2)
				{
					//赤い線で描画
					cv::rectangle(img, cv::Point(leftx, lefty), cv::Point(rightx, righty), cv::Scalar(0, 0, 255), 3);

					printf("描画されました\n");
				}
				else if (color == 3)
				{
					//緑の線で描画
					cv::rectangle(img, cv::Point(leftx, lefty), cv::Point(rightx, righty), cv::Scalar(0, 255, 0), 3);

					printf("描画されました\n");
				}
				else if (color == 4)
				{
					//青の線で描画
					cv::rectangle(img, cv::Point(leftx, lefty), cv::Point(rightx, righty), cv::Scalar(255, 0, 0), 3);

					printf("描画されました\n");
				}
			}
		}
		else if (mode == 8) 
		{
			//リサイズ
			float size;

			printf("変更したい倍率\n");
			scanf("%f", &size);
			resize(img, img, cv::Size(), size, size);

			printf("サイズが変更されました");
		}
		//10を入力した場合
		else if (mode == 10) 
		{
			//画像を保存する

			//項目一覧の表示
			printf("1:PNGフォーマットで保存\n");
			printf("2:JPEGフォーマットで保存\n");
			printf("3:BMPフォーマットで保存\n");

			//保存するフォーマットを決める
			(void)scanf("%d", &format);

			//正しく入力されるまで再入力
			while (format < 1 || format > 3)
			{
				//エラーメッセージ
				printf("一覧の中から選んでください\n\n");

				//項目一覧の表示
				printf("1:PNGフォーマットで保存\n");
				printf("2:JPEGフォーマットで保存\n");
				printf("3:BMPフォーマットで保存\n");

				//保存するフォーマットを決める
				(void)scanf("%d", &format);
			}

			//1を入力した場合
			if (format == 1)
			{
				cv::imwrite("変換後画像.png", img);//pngフォーマットで保存
			}

			//2を入力した場合
			else if (format == 2) 
			{
				cv::imwrite("変換後画像.jpg", img);//jpegフォーマットで保存
			}

			//3を入力した場合
			else if (format == 3)
			{
				cv::imwrite("変換後画像.bmp", img);//bmpフォーマットで保存
			}
		}

		//11を入力した場合
		else if (mode == 11)
		{
			printf("画像のパスを入力する\n");

			//パスの入力
			(void)scanf("%s", path);

			//画像を読み込む
			img = cv::imread(path);


			//エラー処理
			if (img.empty() == true) 
			{
				// 画像の中身が空なら終了する
				return 0;
			}
		}

		//項目一覧の表示
		printf("0:画像を表示する\n");
		printf("1:白黒加工する\n");
		printf("2:トリミングする\n");
		printf("3:反転する\n");
		printf("4:モザイク処理する\n");
		printf("5:画像を回転させる\n");
		printf("6:文字を入れる\n");
		printf("7:図形を描画する\n");
		printf("8:画像サイズの変更\n");
		printf("10:画像を保存する\n");
		printf("11:違う画像を読み込む\n");
		printf("99:終了する\n");

		(void)scanf("%d", &mode);

		//正しく入力されるまで再入力
		while (mode != 0 &&
			mode != 1 &&
			mode != 2 &&
			mode != 3 &&
			mode != 4 &&
			mode != 5 &&
			mode != 6 &&
			mode != 7 &&
			mode != 8 &&
			mode != 10 &&
			mode != 11 &&
			mode != 99)
		{
			//エラーメッセージ
			printf("一覧の中から選んでください\n\n");

			//項目一覧の表示
			printf("0:画像を表示する\n");
			printf("1:白黒加工する\n");
			printf("2:トリミングする\n");
			printf("3:反転する\n");
			printf("4:モザイク処理する\n");
			printf("5:画像を回転させる\n");
			printf("6:文字を入れる\n");
			printf("7:図形を描画する\n");
			printf("8:画像サイズの変更\n");
			printf("10:画像を保存する\n");
			printf("11:違う画像を読み込む\n");
			printf("99:終了する\n");

			(void)scanf("%d", &mode);
		}
	}
	return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
