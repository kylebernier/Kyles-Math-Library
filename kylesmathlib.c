/*******************************************************************************************
 *  _  __     _      _       __  __       _   _       _      _ _                           *
 * | |/ /    | |    ( )     |  \/  |     | | | |     | |    (_) |                          *
 * | ' /_   _| | ___|/ ___  | \  / | __ _| |_| |__   | |     _| |__  _ __ __ _ _ __ _   _  *
 * |  <| | | | |/ _ \ / __| | |\/| |/ _` | __| '_ \  | |    | | '_ \| '__/ _` | '__| | | | *
 * | . \ |_| | |  __/ \__ \ | |  | | (_| | |_| | | | | |____| | |_) | | | (_| | |  | |_| | *
 * |_|\_\__, |_|\___| |___/ |_|  |_|\__,_|\__|_| |_| |______|_|_.__/|_|  \__,_|_|   \__, | *
 *       __/ |                                                                       __/ | *
 *      |___/                                                                       |___/  *
 *******************************************************************************************/

/*********************************************************************************
 * The MIT License (MIT)                                                         *
 * Copyright (c) 2016 Kyle Bernier                                               *
 *                                                                               *
 * Permission is hereby granted, free of charge, to any person obtaining a copy  *
 * of this software and associated documentation files (the "Software"), to deal *
 * in the Software without restriction, including without limitation the rights  *
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell     *
 * copies of the Software, and to permit persons to whom the Software is         *
 * furnished to do so, subject to the following conditions:                      *
 *                                                                               *
 * The above copyright notice and this permission notice shall be included in    *
 * all copies or substantial portions of the Software.                           *
 *                                                                               *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR    *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,      *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE   *
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER        *
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, *
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE *
 * SOFTWARE.                                                                     *
 *********************************************************************************/

/*********************************************************************
 *  _          _                           _   _     _ _ _           *
 * | |        | |                         | | | |   | (_) |          *
 * | | ___   _| | ___  ___ _ __ ___   __ _| |_| |__ | |_| |__   ___  *
 * | |/ / | | | |/ _ \/ __| '_ ` _ \ / _` | __| '_ \| | | '_ \ / __| *
 * |   <| |_| | |  __/\__ \ | | | | | (_| | |_| | | | | | |_) | (__  *
 * |_|\_\\__, |_|\___||___/_| |_| |_|\__,_|\__|_| |_|_|_|_.__(_)___| *
 *        __/ |                                                      *
 *       |___/                                                       *
 *********************************************************************/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kylesmathlib.h"

/* Main method to test math */
int main() {
    // Test matrix math
    struct Matrix a;
    double valuesa[9] = { 5.0, -2.0, 1.0, 0.0, 3.0, -1.0, 2.0, 0.0, 7.0 };
    newMatrix(&a, valuesa, 3, 3);
    struct Matrix b;
    double valuesb[9] = { 1.0, 2.0, 3.0, 0.0, -4.0, 1.0, 0.0, 3.0, -1.0 };
    newMatrix(&b, valuesb, 3, 3);
    printf("A=\n");
    matrixToString(a);
    printf("B=\n");
    matrixToString(b);
    printf("A is %sa square matrix.\n", matrixIsSquare(a) ? "" : "not ");
    printf("B is %sa square matrix.\n", matrixIsSquare(b) ? "" : "not ");
    printf("The determinant of A is %f.\n", matrixDeterminant(a));
    printf("A is %sunique.\n", matrixIsUnique(a) ? "" : "not ");
    printf("The determinant of B is %f.\n", matrixDeterminant(b));
    printf("B is %sunique.\n", matrixIsUnique(b) ? "" : "not ");

    // Add
    struct Matrix aplusb;
    matrixAdd(&aplusb, a, b);
    printf("A+B=\n");
    matrixToString(aplusb);

    // Subtract
    struct Matrix asubb;
    matrixSubtract(&asubb, a, b);
    printf("A-B=\n");
    matrixToString(asubb);

    struct Matrix ascale;
    matrixScale(&ascale, a, 5);
    printf("5A=\n");
    matrixToString(ascale);
    struct Matrix bscale;
    matrixScale(&bscale, b, 5);
    printf("5B=\n");
    matrixToString(bscale);
    printf("A and B are %sthe same size.\n", matrixIsSameSize(a, b) ? "" : "not ");

    printf("A=\n");
    matrixToString(a);
    printf("B=\n");
    matrixToString(b);

    // Test 3D vector math
}

/************************************
 *    _   _          _              *
 *   /_\ | |__ _ ___| |__ _ _ __ _  *
 *  / _ \| / _` / -_) '_ \ '_/ _` | *
 * /_/ \_\_\__, \___|_.__/_| \__,_| *
 *         |___/                    *
 ************************************/

/*************
 * Matricies *
 *************/

/* Create a new matrix */
void newMatrix(struct Matrix *out, double *values, int rows, int columns) {
    out->values = malloc(rows * columns * sizeof(double));
    out->values = values;
    out->numRows = rows;
    out->numColumns = columns;
    out->numValues = rows * columns;
}

/* Add two matricies */
void matrixAdd(struct Matrix *out, struct Matrix a, struct Matrix b) {
    if(!matrixIsSameSize(a, b)) {
        printf("Error: The matricies are not the same size.");
        return;
    }

    double *newValues = malloc(a.numValues * sizeof(double));
    for(int i = 0; i < a.numValues; i++)
        newValues[i] = a.values[i] + b.values[i];

    newMatrix(out, newValues, a.numRows, a.numColumns);
}

/* Subtract two matricies */
void matrixSubtract(struct Matrix *out, struct Matrix a, struct Matrix b) {
    if(!matrixIsSameSize(a, b)) {
        printf("Error: The matricies are not the same size.");
        return;
    }

    double *newValues = malloc(a.numValues * sizeof(double));
    for(int i = 0; i < a.numValues; i++)
        newValues[i] = a.values[i] - b.values[i];

    newMatrix(out, newValues, a.numRows, a.numColumns);
}

/* Scale a matrix */
void matrixScale(struct Matrix *out, struct Matrix a, double s) {
    double *newValues = malloc(a.numValues * sizeof(double));
    for(int i = 0; i < a.numValues; i++)
        newValues[i] = a.values[i]*s;

    newMatrix(out, newValues, a.numRows, a.numColumns);
}

/* Multiply two matricies */
void matrixMultiply(struct Matrix *out, struct Matrix a, struct Matrix b) {

}

/* Calculate the inverse of a matrix */
void matrixInverse(struct Matrix *out, struct Matrix a, struct Matrix b) {

}

/* Calculate the transverse of a matrix */
void matrixTransverse(struct Matrix *out, struct Matrix a) {

}

/* Calculate echelon form of a matrix */
void matrixEchelon(struct Matrix *out, struct Matrix a) {

}

/* Calculate reduced echelon form of a matrix */
void matrixReducedEchelon(struct Matrix *out, struct Matrix a) {
    matrixEchelon(out, a);
}

/* Check if a matrix has a unique solution */
char matrixIsUnique(struct Matrix a) {
    if(matrixDeterminant(a) != 0)
        return 1;

    return 0;
}

/* Check if a matrix is square */
char matrixIsSquare(struct Matrix a) {
    if(a.numColumns == a.numRows)
        return 1;

    return 0;
}

/* Check is two matricies are the same size */
char matrixIsSameSize(struct Matrix a, struct Matrix b) {
    if(a.numColumns == b.numColumns && a.numRows == b.numRows)
        return 1;

    return 0;
}

/* Calculate the determinant of a matrix */
double matrixDeterminant(struct Matrix a) {
    if(!matrixIsSquare(a)) {
        printf("Error: The matrix is not square.");
        return 0;
    }
    int size = a.numColumns;
    double det = 0.0;
    for(int j = 0; j < size; j++) {
        int i = j;
        double temp = 1.0;
        for(int k = 0; k < size; k++, i++) {
            if(i == size) i = 0;
            temp *= a.values[size*k+i];
        }
        det += temp;
    }
    for(int j = 0; j < size; j++) {
        int i = j;
        double temp = 1.0;
        for(int k = 0; k < size; k++, i--) {
            if(i == -1) i = size-1;
            temp *= a.values[size*k+i];
        }
        det -= temp;
    }
    return det;
}

/* Prints the content of a matrix */
void matrixToString(struct Matrix a) {
    for(int i = 0; i < a.numRows; i++) {
        for(int j = 0; j < a.numColumns; j++) {
            printf("%f ", a.values[j+i*a.numRows]);
        }
        printf("\n");
    }
}


/***********
 * Vectors *
 ***********/

/* Create a new vector (points are also defined a vectors) */
void newVector3(struct Vector3 *out, float x, float y, float z) {
    out->x = x;
    out->y = y;
    out->z = z;
}

/* Calculate the magnitude of a vector */
float vect3Magnitude(struct Vector3 v) {
    return sqrt(vect3DotP(v, v));
}

/* Calculate the sum of two vectors */
float vect3Sum(struct Vector3 v) {
    return v.x + v.y + v.z;
}

/* Calculate the dot product of two vectors */
float vect3DotP(struct Vector3 v, struct Vector3 u) {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

/* Calculate the cross product of two vectors */
void vect3CrossP(struct Vector3 *out, struct Vector3 v, struct Vector3 u) {
    newVector3(out, u.y * v.z - v.y * u.z, v.x * u.z - u.x * v.z, u.x * v.y - v.x * u.y);
}

/* Add two vectors */
void vect3Add(struct Vector3 *out, struct Vector3 v, struct Vector3 u) {
    newVector3(out, v.x + u.x, v.y + u.y, v.z + u.z);
}

/* Subtract two vectors */
void vect3Subtract(struct Vector3 *out, struct Vector3 v, struct Vector3 u) {
    newVector3(out, v.x - u.x, v.y - u.y, v.z - u.z);
}

/* Multiply two vectors */
void vect3Multiply(struct Vector3 *out, struct Vector3 v, struct Vector3 u) {
    newVector3(out, v.x * u.x, v.y * u.y, v.z * u.z);
}

/* Scale a vector */
void vect3Scale(struct Vector3 *out, struct Vector3 v, float s) {
    newVector3(out, v.x * s, v.y * s, v.z * s);
}

/* Calculate the projection of a vector */
void vect3Projection(struct Vector3 *out, struct Vector3 v, struct Vector3 u) {
    vect3Scale(out, v, vect3DotP(u, v) / vect3DotP(v, v));
}

/* Calculate whether a ray intersects a triangle */
int vect3Intersection(struct Vector3 vertex1, struct Vector3 vertex2, struct Vector3 vertex3, struct Vector3 rayDirection, struct Vector3 rayOrigin) {
    struct Vector3 edge1, edge2;
    struct Vector3 p, q, t;
    float det, inv_det, u, v;
    float z;
    float epsilon = 0.000001;

    vect3Subtract(&edge1, vertex2, vertex1);
    vect3Subtract(&edge2, vertex3, vertex1);
    vect3CrossP(&p, rayDirection, edge2);
    det = vect3DotP(edge1, p);

    if(det > -epsilon && det < epsilon) return 0;
    inv_det = 1.0f / det;
    vect3Subtract(&t, rayOrigin, vertex1);

    u = vect3DotP(t, p) * inv_det;
    if(u < 0.0f || u > 1.0f) return 0;

    vect3CrossP(&q, t, edge1);

    v = vect3DotP(rayDirection, q) * inv_det;
    if(v < 0.0f || u + v  > 1.0f) return 0;

    z = vect3DotP(edge2, q) * inv_det;

    if(z > epsilon) {
        return 1;
    }

    return 0;
}

/***********************************
 *   ___      _         _          *
 *  / __|__ _| |__ _  _| |_  _ ___ *
 * | (__/ _` | / _| || | | || (_-< *
 *  \___\__,_|_\__|\_,_|_|\_,_/__/ *
 *                                 *
 ***********************************/

/*****************************
 *  ___ _           _        *
 * | _ \ |_ _  _ __(_)__ ___ *
 * |  _/ ' \ || (_-< / _(_-< *
 * |_| |_||_\_, /__/_\__/__/ *
 *          |__/             *
 *****************************/

/*****************
 * Linear Motion *
 *****************/

/*********************
 * Rotational Motion *
 *********************/

/***********
 * Statics *
 ***********/

/*************************
 * Electricity / Magnets *
 *************************/