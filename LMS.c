/*******************************************************************************************************************************************************************
 * 文件名：LMS.c
 * 作者：    IRONMAN
 * 日期：    2016.09.04
 * 版本：     V1.0
 * 说明：  此源文件基于c66x内核实现了最小均方算法(LMS)
 *
 * 算法递推形式：
 * 估计瞬时误差：        e(k) = d(k) - x'(k)w(k)                  (1)
 * 估计滤波系数矢量：w(k+1) = w(k) + 2 niu e(k)x(k)   (2)
 * 初始条件：                w(0) = 0;
 *
 * *****************************************************************************************************************************************************************/
#include <mathlib.h>
#include <dsplib.h>
#include <string.h>
#include "LMS.h"

#pragma DATA_ALIGN(lms_x, 8)
float lms_x[LMS_M];                                                         //输入信号向量存储数组
#pragma DATA_ALIGN(lms_w_forward, 8)
float lms_w_forward[LMS_M];                                       //用于存储未来一时刻滤波系数向量w(k+1)
#pragma DATA_ALIGN(lms_w, 8)
float lms_w[LMS_M];                                                       //用于存储当前时刻滤波系数矢量w(k)

Adaptive_Filter_In    lms_param_in;
Adaptive_Filter_Out  lms_param_out;

void LMS_Gradient_Instantaneous_Estimates(Adaptive_Filter_In *lms_in, Adaptive_Filter_Out* lms_out)
{
    int i;
    static int FIR_order;
    static unsigned char First_in_flag = 1;
    static float *w_ptr, *w_forward_ptr, *Temp_w_ptr;
    static float *x_ptr;
    float  temp;

    if(First_in_flag )
    {
        First_in_flag = 0;
        FIR_order = lms_in->length_x;

        memset((void *)lms_w_forward, 0, FIR_order*4);
        memset((void *)lms_w, 0, FIR_order*4);

        w_forward_ptr = lms_w_forward;
        w_ptr = lms_w;

        x_ptr = lms_in->x_ptr;
    }

/******************************************************************************************************************************/
/**************************************(1)式计算部分****************************************************************************/
/******************************************************************************************************************************/
    lms_out->y =  DSPF_sp_dotprod(x_ptr,w_ptr,FIR_order);               //一共需要82个时钟周期
    lms_out->error = lms_in->d - lms_out->y;
/******************************************************************************************************************************/
/**************************************(2)式计算部分****************************************************************************/
/******************************************************************************************************************************/
    temp = 2*LMS_NIU*lms_out->error;                                 //第二部分一共需要380个时钟周期

    for(i=0; i<FIR_order; i+=8)
    {
        w_forward_ptr[i]      = w_ptr[i]     + temp*x_ptr[i];
        w_forward_ptr[i+1] = w_ptr[i+1] + temp*x_ptr[i+1];
        w_forward_ptr[i+2] = w_ptr[i+2] + temp*x_ptr[i+2];
        w_forward_ptr[i+3] = w_ptr[i+3] + temp*x_ptr[i+3];
        w_forward_ptr[i+4] = w_ptr[i+4] + temp*x_ptr[i+4];
        w_forward_ptr[i+5] = w_ptr[i+5] + temp*x_ptr[i+5];
        w_forward_ptr[i+6] = w_ptr[i+6] + temp*x_ptr[i+6];
        w_forward_ptr[i+7] = w_ptr[i+7] + temp*x_ptr[i+7];
    }
/**************************************************************************************************************************************/
/************************************************************变量更替*******************************************************************/
/**************************************************************************************************************************************/
    Temp_w_ptr = w_forward_ptr;        //新旧滤波系数矢量指针交换
    w_forward_ptr = w_ptr;
    w_ptr = Temp_w_ptr;
}