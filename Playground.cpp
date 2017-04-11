//
//  Playground.cpp
//  cpp11sdl
//
//  Created by George Oros on 4/4/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "Playground.hpp"

#include <cstdlib>
#include <iostream>
#include <chrono>
#include <cstring>
#include <cfloat>

#define SZ_X 16384
#define SZ_Y 16384
#define EXEC_CNT 10

#define BYTE_PATTERN 0x11223344

double Playground::Algo0(std::uint32_t* ptr)
{
    int i;
    int j;

    auto start = std::chrono::high_resolution_clock::now();
    for (i = 0; i < SZ_Y; i++)
    {
        for (j = 0; j < SZ_X; j++)
        {
            ptr[i * SZ_Y + j] = BYTE_PATTERN;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    i = SZ_Y - 1;
    j = SZ_X - 1;
    if (ptr[i * SZ_Y + j] != BYTE_PATTERN)
    {
        std::cout << "Error!" << std::endl;
    }
    return std::chrono::duration<double>(end - start).count();
}

double Playground::Algo1(std::uint32_t* ptr)
{
    int i;
    int j;

    std::uint32_t max = SZ_X * SZ_Y;
    if (max % 16 != 0)
    {
        std::cout << "Loop unroll trebuie facut calumea daca max % 16 != 0!";
    }
    i = 0;
    auto start = std::chrono::high_resolution_clock::now();
    while(i < max)
    {
        *(ptr + i + 0) = BYTE_PATTERN;
        *(ptr + i + 1) = BYTE_PATTERN;
        *(ptr + i + 2) = BYTE_PATTERN;
        *(ptr + i + 3) = BYTE_PATTERN;
        *(ptr + i + 4) = BYTE_PATTERN;
        *(ptr + i + 5) = BYTE_PATTERN;
        *(ptr + i + 6) = BYTE_PATTERN;
        *(ptr + i + 7) = BYTE_PATTERN;
        *(ptr + i + 8) = BYTE_PATTERN;
        *(ptr + i + 9) = BYTE_PATTERN;
        *(ptr + i + 10) = BYTE_PATTERN;
        *(ptr + i + 11) = BYTE_PATTERN;
        *(ptr + i + 12) = BYTE_PATTERN;
        *(ptr + i + 13) = BYTE_PATTERN;
        *(ptr + i + 14) = BYTE_PATTERN;
        *(ptr + i + 15) = BYTE_PATTERN;
        i += 16;
    }
    auto end = std::chrono::high_resolution_clock::now();
    i = SZ_Y - 1;
    j = SZ_X - 1;
    if (ptr[i * SZ_Y + j] != BYTE_PATTERN)
    {
        std::cout << "Error!" << std::endl;
    }
    return std::chrono::duration<double>(end - start).count();
}

double Playground::Algo2(uint32_t* ptr)
{
    int i;
    int j;

    auto start = std::chrono::high_resolution_clock::now();
    std::memset(ptr,0x11,SZ_X * SZ_Y * sizeof(uint32_t));
    auto end = std::chrono::high_resolution_clock::now();
    i = SZ_Y - 1;
    j = SZ_X - 1;
    if (ptr[i * SZ_Y + j] != 0x11111111)
    {
        std::cout << "Error!" << std::endl;
    }
    return std::chrono::duration<double>(end - start).count();
}

void Playground::DoAlgo(int algo_index)
{
    int k;
    double diff[EXEC_CNT];
    std::uint32_t* ptr;
    int step_new;
    int step_old = 0;
    void * buff;
    size_t buffsize;
    double (Playground::*algo_ptr)(uint32_t*);

    switch(algo_index)
    {
        case 0:
            std::cout << "Algo0 selected - standard Matrix" << std::endl;
            algo_ptr = &Playground::Algo0;
            break;
        case 1:
            std::cout << "Algo1 selected - liniar; manual loop unroll" << std::endl;
            algo_ptr = &Playground::Algo1;
            break;
        case 2:
            std::cout << "Algo2 selected - memset" << std::endl;
            algo_ptr = &Playground::Algo2;
            break;
        default:
            std::cout << "Wrong algo index" << std::endl;
            std::exit(2);
            break;
    }
    buffsize = SZ_X * SZ_Y * sizeof(uint32_t);

    std::cout << ((buffsize / 1024.0) / 1024.0) << "MB dataset" << std::endl;
    buff = std::malloc(buffsize);
    if (buff == NULL)
    {
        std::cout << "malloc fail!" << std::endl;
        exit(1);
    }
    
    ptr = (std::uint32_t *)buff;

    (void)((this)->*(algo_ptr))(ptr);
    for (k = 0; k < EXEC_CNT; k++)
    {
        step_new = (k * 100) / EXEC_CNT;
        if (step_new != step_old)
        {
            if (step_new % 5 == 0) std::cout << ".";
            std::cout.flush();
            step_old = step_new;
        }
        diff[k] = ((this)->*(algo_ptr))(ptr);
        std::memset(buff,0,buffsize);
    }
    std::cout << " done." << std::endl;
    double sum = 0.0;
    double min = DBL_MAX;
    double max = DBL_MIN;
    int min_index = -1;
    int max_index = -1;
    for( k = 0; k < EXEC_CNT; k++)
    {
        sum += diff[k];
        if (diff[k] < min)
        {
            min = diff[k];
            min_index = k;
        }
        if (diff[k] > max)
        {
            max = diff[k];
            max_index = k;
        }
    }
    double avg = sum / EXEC_CNT;
    std::cout << "Done in " << sum << "sec. " << EXEC_CNT << " runs" << std::endl;
    std::cout << "Average of " << avg << "sec" << std::endl;
    std::cout << "Min " << min << "sec. Run " << min_index << std::endl;
    std::cout << "Max " << max << "sec. Run " << max_index << std::endl;
    double bytes_written = (double)EXEC_CNT * (double)SZ_X * (double)SZ_Y * (double)sizeof(uint32_t);
    double bw = (((bytes_written / sum) / 1024.0) / 1024.0 / 1024.0);
    std::cout << "Bandwidth=" << bw << " GB/sec" << std::endl;
    std::free(buff);
}

void Playground::Play(void)
{
    std::cout << "****************************************" << std::endl;
    DoAlgo(0);
    std::cout << "****************************************" << std::endl;
    DoAlgo(1);
    std::cout << "****************************************" << std::endl;
    DoAlgo(2);
    //std::exit(0);
}

int main(int argc, const char * argv[])
{
    Playground p;
    p.Play();
    //std::cin.get();
}