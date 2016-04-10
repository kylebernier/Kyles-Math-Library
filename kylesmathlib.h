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

/************************************************************************
 *  _          _                           _   _     _ _ _       _      *
 * | |        | |                         | | | |   | (_) |     | |     *
 * | | ___   _| | ___  ___ _ __ ___   __ _| |_| |__ | |_| |__   | |__   *
 * | |/ / | | | |/ _ \/ __| '_ ` _ \ / _` | __| '_ \| | | '_ \  | '_ \  *
 * |   <| |_| | |  __/\__ \ | | | | | (_| | |_| | | | | | |_) | | | | | *
 * |_|\_\\__, |_|\___||___/_| |_| |_|\__,_|\__|_| |_|_|_|_.__(_)|_| |_| *
 *        __/ |                                                         *
 *       |___/                                                          *
 ************************************************************************/

#ifndef KYLESMATHLIB_H_
#define KYLESMATHLIB_H_

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

 /* Matrix Structure */
struct Matrix {
    double *values;
    int numRows, numColumns, numValues;
};

/* Create a new matrix */
void newMatrix(struct Matrix *out, double *values, int rows, int columns);

/* Add two matricies */
void matrixAdd(struct Matrix *out, struct Matrix a, struct Matrix b);

/* Subtract two matricies */
void matrixSubtract(struct Matrix *out, struct Matrix a, struct Matrix b);

/* Scale a matrix */
void matrixScale(struct Matrix *out, struct Matrix a, double s);

/* Multiply two matricies */
void matrixMultiply(struct Matrix *out, struct Matrix a, struct Matrix b);

/* Calculate the inverse of a matrix */
void matrixInverse(struct Matrix *out, struct Matrix a, struct Matrix b);

/* Calculate the transverse of a matrix */
void matrixTransverse(struct Matrix *out, struct Matrix a);

/* Calculate echelon form of a matrix */
void matrixEchelon(struct Matrix *out, struct Matrix a);

/* Calculate reduced echelon form of a matrix */
void matrixReducedEchelon(struct Matrix *out, struct Matrix a);

/* Check if a matrix has a unique solution */
char matrixIsUnique(struct Matrix a);

/* Check if a matrix is square */
char matrixIsSquare(struct Matrix a);

/* Check is two matricies are the same size */
char matrixIsSameSize(struct Matrix a, struct Matrix b);

/* Calculate the determinant of a matrix */
double matrixDeterminant(struct Matrix a);

/* Prints the content of a matrix */
void matrixToString(struct Matrix a);


/***********
 * Vectors *
 ***********/

/* Vector Structure */
struct Vector3 {
    float x, y, z;
};

/* Create a new vector (points are also defined a vectors) */
void newVector3(struct Vector3 *out, float x, float y, float z);

/* Calculate the magnitude of a vector */
float vect3Magnitude(struct Vector3 v);

/* Calculate the sum of two vectors */
float vect3Sum(struct Vector3 v);

/* Calculate the dot product of two vectors */
float vect3DotP(struct Vector3 v, struct Vector3 u);

/* Calculate the cross product of two vectors */
void vect3CrossP(struct Vector3 *out, struct Vector3 v, struct Vector3 u);

/* Add two vectors */
void vect3Add(struct Vector3 *out, struct Vector3 v, struct Vector3 u);

/* Subtract two vectors */
void vect3Subtract(struct Vector3 *out, struct Vector3 v, struct Vector3 u);

/* Multiply two vectors */
void vect3Multiply(struct Vector3 *out, struct Vector3 v, struct Vector3 u);

/* Scale a vector */
void vect3Scale(struct Vector3 *out, struct Vector3 v, float s);

/* Calculate the projection of a vector */
void vect3Projection(struct Vector3 *out, struct Vector3 v, struct Vector3 u);

/* Calculate whether a ray intersects a triangle */
int vect3Intersection(struct Vector3 vertex1, struct Vector3 vertex2, struct Vector3 vertex3, struct Vector3 rayDirection, struct Vector3 rayOrigin);


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


#endif