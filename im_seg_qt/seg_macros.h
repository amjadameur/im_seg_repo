#ifndef SEG_MACROS_H
#define SEG_MACROS_H

#define GREEN_TRESH (150)
#define WHITE ((uchar) 255)
#define BLACK ((uchar) 0)

#define GET_GREEN(x) ((x & GREEN_MASK) >> GREEN_OFFSET)
#define GREEN_MASK ((QRgb) 0x000000FF << GREEN_OFFSET)
#define GREEN_OFFSET (8)


#endif // SEG_MACROS_H
