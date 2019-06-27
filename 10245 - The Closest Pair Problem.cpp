#include<bits/stdc++.h>
using namespace std;
struct Point
{
    double x;
    double y;
    Point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
};
bool compX(const Point& a, const Point& b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
bool compY(const Point& a, const Point& b)
{
    if(a.y==b.y)
        return a.x<b.x;
    return a.y<b.y;
}
vector<Point> point;
double minDist;
void Update(const Point& a, const Point& b)
{
    double dist = sqrt(pow(a.x-b.x,2.0) + pow(a.y-b.y,2.0));
    if(dist<minDist) minDist = dist;
}
void solve(int l, int r)
{
    if(r-l+1 <=3){
        for(int i=l; i<=r; i++){
            for(int j = i+1; j<=r; j++)
                Update(point[i], point[j]);
        }
        return;
    }
    int m = (l+r)/2;
    solve(l,m);
    solve(m,r);
    vector<Point> tem;
    for(int i=l; i<=r; i++){
        if(abs(point[i].x-point[m].x)<minDist){
            tem.push_back(point[i]);
        }
    }
    sort(tem.begin(), tem.end(),compY);
    for(int i=0; i<tem.size(); i++){
        for(int j=i+1; j<tem.size(); j++){
            if(tem[j].y - tem[i].y >= minDist) break;
            Update(tem[i], tem[j]);
        }
    }
}
int main()
{
    int n;
    double x,y;
    while(scanf("%d",&n),n){
        point.clear();
        for(int i=0; i<n; i++){
            scanf("%lf%lf",&x,&y);
            point.push_back(Point(x,y));
        }
        sort(point.begin(), point.end(),compX);
        minDist = 1e20;
        solve(0,n-1);
        if(minDist>=10000) printf("INFINITY\n");
        else printf("%.4f\n",minDist);
    }
}
