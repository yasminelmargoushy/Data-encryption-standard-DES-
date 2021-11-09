#include <iostream>
#include <stdint.h>
#include <cstdlib>
#include <assert.h>
#include <string>
#include <map>

/******************************************************************************************/
/************************************   Tables  *******************************************/
/******************************************************************************************/

/***************    Plain Text/Cipher Text Tables   ***************/
/******************************************************************/

/***************    Initial Permutation Table   ***************/
const uint8_t InitialPermutationTable [64] = { 58, 50, 42, 34, 26, 18, 10, 2,
                                         60, 52, 44, 36, 28, 20, 12, 4,
                                         62, 54, 46, 38, 30, 22, 14, 6,
                                         64, 56, 48, 40, 32, 24, 16, 8,
                                         57, 49, 41, 33, 25, 17, 9, 1,
                                         59, 51, 43, 35, 27, 19, 11, 3,
                                         61, 53, 45, 37, 29, 21, 13, 5,
                                         63, 55, 47, 39, 31, 23, 15, 7 };

/*********    Inverse Initial Permutation Table   *************/
const uint8_t InverseInitialPermutationTable[64] = { 40, 8, 48, 16, 56, 24, 64, 32,
                                               39, 7, 47, 15, 55, 23, 63, 31,
                                               38, 6, 46, 14, 54, 22, 62, 30,
                                               37, 5, 45, 13, 53, 21, 61, 29,
                                               36, 4, 44, 12, 52, 20, 60, 28,
                                               35, 3, 43, 11, 51, 19, 59, 27,
                                               34, 2, 42, 10, 50, 18, 58, 26,
                                               33, 1, 41, 9, 49, 17, 57, 25 };

/***************    Expansion Permutation Table   ***************/
const uint8_t ExpansionPermutationTable[48] = { 32, 1, 2, 3, 4, 5,
                                          4, 5, 6, 7, 8, 9,
                                          8, 9, 10, 11, 12, 13,
                                          12, 13, 14, 15, 16, 17,
                                          16, 17, 18, 19, 20, 21,
                                          20, 21, 22, 23, 24, 25,
                                          24, 25, 26, 27, 28, 29,
                                          28, 29, 30, 31, 32, 1 };

/********************** Permutation Table   *******************/
const uint8_t PermutationTable[32] = { 16, 7, 20, 21,
                                29, 12, 28, 17,
                                1, 15, 23, 26,
                                5, 18, 31, 10,
                                2, 8, 24, 14,
                                32, 27, 3, 9,
                                19, 13, 30, 6,
                                22, 11, 4, 25 };

/********************** S-box Table ***************************/
const uint8_t S_BoxTable[8][4][16] = { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
                                  0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
                                  4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
                                  15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 },
                                { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
                                  3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
                                  0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
                                  13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 },

                                { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
                                  13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
                                  13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
                                  1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 },
                                { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
                                  13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
                                  10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
                                  3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 },
                                { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
                                  14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
                                  4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
                                  11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 },
                                { 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
                                  10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
                                  9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
                                  4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 },
                                { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
                                  13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
                                  1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
                                  6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 },
                                { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
                                  1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
                                  7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
                                  2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 } };

/***********************    Key Tables   **************************/
/******************************************************************/

/************    Permutation Choice 1 Table   *****************/
const uint8_t PermutationChoice1Table [56] = { 57, 49, 41, 33, 25, 17, 9,
                                                1, 58, 50, 42, 34, 26, 18,
                                                10, 2, 59, 51, 43, 35, 27,
                                                19, 11, 3, 60, 52, 44, 36,
                                                63, 55, 47, 39, 31, 23, 15,
                                                7, 62, 54, 46, 38, 30, 22,
                                                14, 6, 61, 53, 45, 37, 29,
                                                21, 13, 5, 28, 20, 12, 4 };


/************    Permutation Choice 2 Table   *************/
const uint8_t PermutationChoice2Table [48] = { 14, 17, 11, 24, 1, 5,
                                                3, 28, 15, 6, 21, 10,
                                                23, 19, 12, 4, 26, 8,
                                                16, 7, 27, 20, 13, 2,
                                                41, 52, 31, 37, 47, 55,
                                                30, 40, 51, 45, 33, 48,
                                                44, 49, 39, 56, 34, 53,
                                                46, 42, 50, 36, 29, 32 };

/***************    Left Shift Round Table   **************/
const uint8_t LeftShiftRoundTable[16] = { 1, 1, 2, 2, 2, 2, 2, 2,
                                          1, 2, 2, 2, 2, 2, 2, 1 };

/******************************************************************************************/
/******************************   Bit Manipulations  **************************************/
/******************************************************************************************/

inline uint64_t GET_BIT(const uint64_t VAR, uint8_t X)
{
    return ((VAR >> X) & (uint64_t) 1);
}

inline void SET_BIT(uint64_t& VAR, uint8_t X)
{
    (VAR = VAR | ((uint64_t)1 << X));
}
inline void CLR_BIT(uint64_t& VAR, uint8_t X)
{
    (VAR = VAR & (~((uint64_t)1 << X)));
}


/******************************************************************************************/
/************************   Global Variables & Prototypes  ********************************/
/******************************************************************************************/

uint8_t RoundNumber = 0;
uint64_t Keys48[16] = { 0 };
uint64_t Text64[16] = { 0 };


uint64_t Permute(const uint64_t Copy_Variable, const uint8_t* PermutateTable, uint8_t Length, uint8_t Orignial_Length);
uint64_t LeftCircularShift(uint64_t Copy_Variable);
uint64_t SingleRound(const uint64_t Copy_Variable);
uint64_t  S_BoxSubstitute(const uint64_t Copy_Variable);
uint64_t  Swap(const uint64_t Copy_Variable);
uint64_t hex2int(std::string HexaString, uint8_t Length);

/******************************************************************************************/
/**********************************   Functions  ******************************************/
/******************************************************************************************/

int main(int argc, char* argv[])
{
    //assert((strcmp(argv[1], "encrypt") == 0) || (strcmp(argv[1], "decrypt") == 0));
    //assert(argc == 4);
    std::string OperationStr = "", Text64Str = "", Key64Str = "";
    if (argc != 4)
    {
        std::cout << "No Command Line Arguments" << std::endl;
        std::cout << "Enter Operation(encrypt/decrypt): ";
        std::cin >> OperationStr;
        std::cout << "Enter Text in Hexadecimal (Don't Add 0x): ";
        std::cin >> Text64Str;
        std::cout << "Enter Key in Hexadecimal (Don't Add 0x): ";
        std::cin >> Key64Str;
    }
    else
    {
        OperationStr = argv[1];
        Text64Str = argv[2];
        Key64Str = argv[3];
    }
    bool OperationDecrypt = (OperationStr == "decrypt");

    uint64_t RootText64 = 0;
    RootText64 = hex2int(Text64Str, Text64Str.length());
    
    uint64_t RootKey64;
    RootKey64 = hex2int(Key64Str, Key64Str.length());

    uint64_t RootKey56 = Permute(RootKey64, PermutationChoice1Table, 56, 64);

    uint64_t UpperHalf = RootKey56 >> 28;
    uint64_t LowerHalf = RootKey56 & 0xfffffff;

    for (RoundNumber = 0; RoundNumber < 16; RoundNumber++)
    {
        UpperHalf = LeftCircularShift(UpperHalf);
        LowerHalf = LeftCircularShift(LowerHalf);
        RootKey56 = LowerHalf | (UpperHalf << 28);
        Keys48[RoundNumber] = Permute(RootKey56, PermutationChoice2Table, 48, 56);
    }

    if (OperationDecrypt)
    {
        uint8_t i = 0;
        uint8_t j = 15;
        while (i < j) 
        {
            uint64_t temp = Keys48[i];
            Keys48[i] = Keys48[j];
            Keys48[j] = temp;
            i++;
            j--;
        }
    }

    RootText64 = Permute(RootText64, InitialPermutationTable, 64, 64);

    RoundNumber = 0;
    for (RoundNumber = 0; RoundNumber < 16; RoundNumber++)
    {
        if (RoundNumber == 0)
        {
            Text64[RoundNumber] = SingleRound(RootText64);
        }
        else
        {
            Text64[RoundNumber] = SingleRound(Text64[RoundNumber - 1]);
        }
    }
    uint64_t FinalText64 = Swap(Text64[15]);
    FinalText64 = Permute(FinalText64, InverseInitialPermutationTable, 64, 64);

    if (!OperationDecrypt)
    {
        std::cout << "Cipher Text: " << std::uppercase << std::hex << FinalText64;
    }
    else
    {
        std::cout << "Plain Text: " << std::uppercase << std::hex << FinalText64;
    }
}

uint64_t  S_BoxSubstitute(const uint64_t Copy_Variable)
{
    uint64_t Local_ReturnVariable = 0;
    uint8_t InputArray[8] = { 0 };
    uint8_t OutputArray[8] = { 0 };
    for (uint8_t i = 0; i < 8; i++)
    {
        InputArray[i] = (Copy_Variable >> (7 - i) * 6) & 0x3f;
        uint8_t RowNum = (InputArray[i] & 0x01) | ((InputArray[i] & 0x20) >> 4);
        uint8_t ColNum = (InputArray[i] >> 1) & 0x0f;
        OutputArray[i] = S_BoxTable[i][RowNum][ColNum];
        Local_ReturnVariable |= (((uint64_t)OutputArray[i] & 0x0f) << (((uint64_t)7 - i) * 4));
    }
    return Local_ReturnVariable & 0xffffffff;
}

uint64_t  Swap(const uint64_t Copy_Variable)
{
    uint64_t Local_ReturnVariable = 0;
    uint64_t UpperHalf = Copy_Variable >> 32;
    uint64_t LowerHalf = Copy_Variable & 0xffffffff;
    Local_ReturnVariable = UpperHalf | (LowerHalf << 32);
    return Local_ReturnVariable;
}

uint64_t SingleRound(const uint64_t Copy_Variable)
{
    uint64_t Local_ReturnVariable = 0;
    uint64_t UpperHalf = Copy_Variable >> 32;
    uint64_t LowerHalf = Copy_Variable & 0xffffffff;
    uint64_t FutureUpper = LowerHalf;
    uint64_t FutureLower = Permute(LowerHalf, ExpansionPermutationTable, 48, 32);
    FutureLower = FutureLower ^ Keys48[RoundNumber];
    FutureLower = S_BoxSubstitute(FutureLower);
    FutureLower = Permute(FutureLower, PermutationTable, 32, 32);
    FutureLower = FutureLower ^ UpperHalf;
    Local_ReturnVariable = FutureLower | (FutureUpper << 32);
    // std::cout << "Round " << RoundNumber + 1 << " :" << std::uppercase << std::hex << Local_ReturnVariable << std::endl;
    return Local_ReturnVariable;
}


uint64_t LeftCircularShift(uint64_t Copy_Variable)
{
    for (uint8_t i = 0; i < LeftShiftRoundTable[RoundNumber]; i++)
    {
        uint64_t bit1 = GET_BIT(Copy_Variable, 27);
        Copy_Variable = ((Copy_Variable << 1) | bit1) & 0xfffffff;
    }
    return Copy_Variable;
}

uint64_t Permute(const uint64_t Copy_Variable, const uint8_t* PermutateTable, uint8_t Length, uint8_t Orignial_Length)
{
    uint64_t Local_ReturnVariable = 0;
    for (uint8_t i = 0; i < Length; i++)
    {
        if (GET_BIT(Copy_Variable, Orignial_Length - PermutateTable[i]))
        {
            SET_BIT(Local_ReturnVariable, (Length - i - 1));
        }
    }
    return Local_ReturnVariable;
}


uint64_t hex2int(std::string HexaString, uint8_t Length)
{
    uint64_t Local_ReturnVariable = 0;
    uint8_t i;
    for (i = 0; i < Length; i++)
    {
        if (HexaString[i] >= '0' && HexaString[i] <= '9')
            Local_ReturnVariable += ((uint64_t)HexaString[i] - '0') * ((uint64_t)1 << (4 * (Length - 1 - i)));
        else if (HexaString[i] >= 'A' && HexaString[i] <= 'F')
            Local_ReturnVariable += ((uint64_t)HexaString[i] + 10 - 'A') * ((uint64_t)1 << (4 * (Length - 1 - i)));
        else if (HexaString[i] >= 'a' && HexaString[i] <= 'f')
            Local_ReturnVariable += ((uint64_t)HexaString[i] + 10 - 'a') * ((uint64_t)1 << (4 * (Length - 1 - i)));
        else
        {
            std::cout << "[ERROR] Detected an undefined Symbole in The Hexadecimal Number." << std::endl;
            exit(1);
        }
    }
    return Local_ReturnVariable;
}