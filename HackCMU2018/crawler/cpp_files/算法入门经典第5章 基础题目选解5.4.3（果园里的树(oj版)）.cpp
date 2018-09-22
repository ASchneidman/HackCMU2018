#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

struct POINT {int x; int y;};

using namespace std;

//主函数

int main(void)
{
	for (POINT Coord[3], Tree; ;)
	{ //循环处理每一组输入的数据
		POINT Min = {10000, 10000}, Max = {0, 0};
		for (int i = 0; i < 3; ++i)
		{ //读取输入的3个顶点坐标值
			float fX, fY;
			if (0 == (cin >> fX >> fY))
				return 0;
				
			Coord[i].x = (int)(fX * 100 + 0.5); //放大100倍取整
			Coord[i].y = (int)(fY * 100 + 0.5); //整数运算可保证精度

			//统计最大和最小的坐标值
			if (Coord[i].x < Min.x)
				Min.x = Coord[i].x;

			if (Coord[i].y < Min.y) 
				Min.y = Coord[i].y;

			if (Coord[i].x > Max.x)
				Max.x = Coord[i].x;

			if (Coord[i].y > Max.y)
				Max.y = Coord[i].y;

		}

		//坐标最值没变，说明所给数据不在范围内

		if (Min.x > Max.x || Min.y > Max.y)
			cout << "   0" << endl;

		//全0表示输入结束
		if (Coord[0].x == 0 && Coord[0].y == 0 &&
			Coord[1].x == 0 && Coord[1].y == 0 &&
			Coord[2].x == 0 && Coord[2].y == 0)
			break;

		POINT Vec[3] = { //建立三条边的向量
			{Coord[1].x - Coord[0].x, Coord[1].y - Coord[0].y},
			{Coord[2].x - Coord[1].x, Coord[2].y - Coord[1].y},
			{Coord[0].x - Coord[2].x, Coord[0].y - Coord[2].y},
		};

		//检查三个点是否以顺时针方向给出
		if (Vec[0].x * Vec[1].y - Vec[1].x * Vec[0].y > 0)
		{
			swap(Coord[0], Coord[1]);
			Vec[0].x = Coord[1].x - Coord[0].x;
			Vec[0].y = Coord[1].y - Coord[0].y;
			Vec[1].x = Coord[2].x - Coord[1].x;
			Vec[1].y = Coord[2].y - Coord[1].y;
			Vec[2].x = Coord[0].x - Coord[2].x;
			Vec[2].y = Coord[0].y - Coord[2].y;
		}

		//最小值和最大值分别取整
		if (Min.x % 100 != 0)
			Min.x = (Min.x / 100 + 1) * 100;

		if (Min.y % 100 != 0)
			Min.y = (Min.y / 100 + 1) * 100;

		if (Max.x % 100 != 0)
			Max.x = Max.x / 100 * 100;

		if (Max.y % 100 != 0)
			Max.y = Max.y / 100 * 100;

		//约束最值
		if (Min.x < 100)
			Min.x = 100;

		if (Min.y < 100)
			Min.y = 100;

		if (Max.x > 9900)
			Max.x = 9900;

		if (Max.y > 9900)
			Max.y = 9900;

		int nCnt = 0, i;

		//在三角形外接矩形的范围内遍例每一个点，检查是否在三角形内
		for (Tree.y = Min.y; Tree.y <= Max.y; Tree.y += 100)
			for (Tree.x = Min.x; Tree.x <= Max.x; Tree.x += 100)
			{
				for (i = 0; i < 3; ++i)
				{
					POINT VecT = {Coord[i].x - Tree.x, Coord[i].y - Tree.y};
					if (VecT.x * Vec[i].y - VecT.y * Vec[i].x > 0)
						break;
				}
				nCnt += (i == 3);
			}

		//按格式要求输出结果
		cout << setw(4) << nCnt << endl;
	}
	return 0;
}