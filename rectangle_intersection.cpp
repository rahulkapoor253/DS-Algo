#include <bits/stdc++.h>

using namespace std;

struct Rectangle
{
	int x, y;
	int width, height;
};

bool rectangleIntersection(Rectangle R1, Rectangle R2) {
//all scenarios should be fulfilled here
	return (R1.x <= R2.x + R2.width) && (R2.x <= R1.x + R1.width) &&
	       (R1.y <= R2.y + R2.height) && (R2.y <= R1.y + R1.height);
}

Rectangle findRectangleIntersection(Rectangle R1, Rectangle R2) {

	Rectangle Res;
	Res.x = 0;
	Res.y = 0;
	Res.width = 0;
	Res.height = 0;

	if (rectangleIntersection(R1, R2)) {

		Res.x = max(R1.x, R2.x);
		Res.y = max(R1.y, R2.y);
		Res.width = min(R1.x + R1.width, R2.x + R2.width) - Res.x;
		Res.height = min(R1.y + R1.height, R2.y + R2.height) - Res.y;

	}

	return Res;
}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	int x1, y1, w1, h1;
	int x2, y2, w2, h2;

	cin >> x1 >> y1 >> w1 >> h1;
	cin >> x2 >> y2 >> w2 >> h2;

	Rectangle R1, R2;

	R1.x = x1;
	R1.y = y1;
	R1.width = w1;
	R1.height = h1;

	R2.x = x2;
	R2.y = y2;
	R2.width = w2;
	R2.height = h2;

	Rectangle res = findRectangleIntersection(R1, R2);
	cout << "(" << res.x << "," << res.y << ")" << endl;
	cout << "width: " << res.width << endl;
	cout << "height: " << res.height << endl;

	return 0;
}




