#include<bits/stdc++.h>
using namespace std;

struct point
{
	int x, y;
};

point P0;



void swap(point &p1, point &p2)
{
	point temp=p1;
	p1=p2;
	p2=temp;
}

int DistSq(point p1, point p2)
{
	int ans=(p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
	return ans;
}

int orientation(point p, point q, point r)
{
	int val=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
	if(val==0)return 0; //colinear
	else if(val>0)return 2; //clockwise
	return 1; //anticlockwise
}

int compare(const void *vp1, const void *vp2)
{
	point *p1=(point *)vp1;
	point *p2=(point *)vp2;

	int o=orientation(P0, *p1, *p2);
	if(o==0)
	{
		if(DistSq(P0, *p2)>=DistSq(P0, *p1))return -1;
		else return 1;
	}
	if(o==2) return -1;
	return 1;
}
point stack_2(stack <point> &s)
{
	point p=s.top();
	s.pop();
	point answer=s.top();
	s.push(p);
	return answer;
}

void Convex_Hull(point pt[], int n)
{
	int xmin=pt[0].x;
	int min=0;
	for(int i=1;i<n;++i)
	{
		if(pt[i].x<xmin||(pt[i].x==xmin&&pt[i].y<pt[min].y))
			{
				min=i;
				xmin=pt[i].x;
			}
	}

	swap(pt[0], pt[min]);

	P0=pt[0];
	qsort(&pt[1], n-1, sizeof(point), compare);
	int m=1;
	for(int i=1;i<n;++i)
	{
		while(i<n-1&&orientation(P0, pt[i], pt[i+1])==0)
			i++;
		pt[m]=pt[i];
		m++;
	}

	if(m<3){cout<<"Convex Hull not possible"<<endl;return;}

	stack <point> s;
	s.push(P0);
	s.push(pt[1]);
	s.push(pt[2]);

	for(int i=3;i<m;++i)
	{
		while(orientation(stack_2(s), s.top(), pt[i])!=2)
			s.pop();
		s.push(pt[i]);
	}
	cout<<s.size()<<endl;
	vector <point> v;
	while(!s.empty())
	{
		point p=s.top();
		v.push_back(p);
		s.pop();
	}
	for(int i=v.size()-1;i>=0;--i)
		{cout<<v[i].x<<" "<<v[i].y<<endl;}
}

int main()
{
	int n;
	cin>>n;
	point pts[n];
	for(int i=0;i<n;++i)
	{
		cin>>pts[i].x>>pts[i].y;
	}
	Convex_Hull(pts, n);
	return 0;
}
