//
// Created by o on 10/26/15.
//

#ifndef MONITOR_CTHULHU_SCANLINE_H
#define MONITOR_CTHULHU_SCANLINE_H

#include "structs.h"
#include "base_functions.h"

//
// Created by o on 10/26/15.
//

#include "../header/scanLine.h"

typedef struct tEdge {
    int yUpper;
    float xIntersect, dxPerScan;
    struct tEdge * next;
} Edge;

/* Inserts edge into list in order of increasing xIntersect field. */
void insertEdge (Edge * list, Edge * edge);
int yNext (int k, int cnt, struct Point2D * pts);
void makeEdgeRec (struct Point2D lower, struct Point2D upper, int yComp, Edge * edge, Edge * edges[]);
void buildEdgeList (int cnt, struct Point2D * pts, Edge * edges[]);
void buildActiveList (int scan, Edge * active, Edge * edges[]);
void fillScan (int scan, Edge * active, struct Window *window, struct BufferDevice *device);
void deleteAfter (Edge * q);
void updateActiveList (int scan, Edge * active);
void resortActiveList (Edge * active);
void scanFill (struct Object2D * object, struct Window *window, struct BufferDevice *device);

#endif //MONITOR_CTHULHU_SCANLINE_H
