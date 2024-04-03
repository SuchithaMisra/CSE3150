#ifndef _MY_DISTANCE_H
#define _MY_DISTANCE_H

struct MyDistance {
    int id1, id2;
    double cosine_distance;

    MyDistance(): id1(-1), id2(-1), cosine_distance(0.0) {};

    MyDistance(const MyDistance &dist): id1(dist.id1), id2(dist.id2), cosine_distance(dist.cosine_distance) {};

    MyDistance(int id1, int id2, double cosine_distance): id1(id1), id2(id2), cosine_distance(cosine_distance) {};
};

#endif
