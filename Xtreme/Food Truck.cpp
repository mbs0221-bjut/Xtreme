#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <algorithm>

#define RADIUS 6371.393
#define PI 3.1415926535898

struct subscriber {
	int Y, M, D, h, m;
	double Latitude, Longitude, Distance;
	long PhoneNumber;
	void print() {
		printf("%ld %lf\n", PhoneNumber, Distance);
	}
};

double arc(double r) {
	return PI*r / 180;
}

double dis(double lat1, double long1, double lat2, double long2) {
	double d;
	double dt = arc(lat2 - lat1);
	double dg = arc(long2 - long1);
	d = 2 * RADIUS*asin(sqrt(sin(dt / 2)*sin(dt / 2) + cos(lat1)* cos(lat2)*sin(dg / 2)*sin(dg / 2)));
	return d;
}

time_t strptime(subscriber *s) {
	tm tm_;
	tm_.tm_year = s->Y - 1900;
	tm_.tm_mon = s->M;
	tm_.tm_mday = s->D;
	tm_.tm_hour = s->h;
	tm_.tm_min = s->m;
	tm_.tm_sec = 0;
	time_t t_ = mktime(&tm_);
	return t_;
}

int cmp(const void *a, const void *b) {
	subscriber *p1 = (subscriber*)a;
	subscriber *p2 = (subscriber*)b;
	time_t t1 = strptime(p1);
	time_t t2 = strptime(p2);
	if (p1->PhoneNumber < p2->PhoneNumber) return -1;
	else if (p1->PhoneNumber > p2->PhoneNumber) return 1;
	else {
		if (t1 < t2)return 1;
		else if (t1 > t2)return -1;
		else return 0;
	}
}

subscriber subs[50000];

int main() {
	int i, j, C, RET;
	char str[64];
	double Latitude, Longitude, Radius;
	scanf("%lf,%lf", &Latitude, &Longitude);
	scanf("%lf", &Radius);
	scanf("%s", str);
	i = 0;
	while (
		(RET = scanf("%02d/%02d/%04d %02d:%02d,%lf,%lf,%ld",
			&subs[i].D, &subs[i].M, &subs[i].Y, &subs[i].h, &subs[i].m,
			&subs[i].Latitude, &subs[i].Longitude, &subs[i].PhoneNumber)) != EOF) {
		if (RET == 1)break;
		subs[i].Distance = dis(arc(Latitude), arc(Longitude), arc(subs[i].Latitude), arc(subs[i].Longitude));
		i++;
	}
	C = i;
	qsort(subs, C, sizeof(subscriber), cmp);
	for (i = 0, j = 0; i < C; i++) {
		if (i > 0 && subs[i - 1].PhoneNumber == subs[i].PhoneNumber) {
			continue;
		}
		if (0.99*Radius > subs[i].Distance) {
			if (j > 0)printf(",");
			printf("%ld", subs[i].PhoneNumber);
			j++;
		}
	}
	scanf("%d", &C);
	return 0;
}