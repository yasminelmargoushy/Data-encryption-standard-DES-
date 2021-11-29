#include <iostream>

#ifdef __GNUC__
# define __rdtsc __builtin_ia32_rdtsc
#else
# include<intrin.h>
#endif

/******************************************************************************************/
/************************************   Tables  *******************************************/
/******************************************************************************************/

/***************    Plain Text/Cipher Text Tables   ***************/
/******************************************************************/

/***************    Initial Permutation Table   ***************/
const unsigned char InitialPermutationTable [64] = { 58, 50, 42, 34, 26, 18, 10, 2,
                                                     60, 52, 44, 36, 28, 20, 12, 4,
                                                     62, 54, 46, 38, 30, 22, 14, 6,
                                                     64, 56, 48, 40, 32, 24, 16, 8,
                                                     57, 49, 41, 33, 25, 17, 9, 1,
                                                     59, 51, 43, 35, 27, 19, 11, 3,
                                                     61, 53, 45, 37, 29, 21, 13, 5,
                                                     63, 55, 47, 39, 31, 23, 15, 7 };

/*********    Inverse Initial Permutation Table   *************/
const unsigned char InverseInitialPermutationTable[64] = { 40, 8, 48, 16, 56, 24, 64, 32,
                                                           39, 7, 47, 15, 55, 23, 63, 31,
                                                           38, 6, 46, 14, 54, 22, 62, 30,
                                                           37, 5, 45, 13, 53, 21, 61, 29,
                                                           36, 4, 44, 12, 52, 20, 60, 28,
                                                           35, 3, 43, 11, 51, 19, 59, 27,
                                                           34, 2, 42, 10, 50, 18, 58, 26,
                                                           33, 1, 41, 9, 49, 17, 57, 25 };

/***************    Expansion Permutation Table   ***************/
const unsigned char ExpansionPermutationTable[48] = { 32, 1, 2, 3, 4, 5,
                                                      4, 5, 6, 7, 8, 9,
                                                      8, 9, 10, 11, 12, 13,
                                                      12, 13, 14, 15, 16, 17,
                                                      16, 17, 18, 19, 20, 21,
                                                      20, 21, 22, 23, 24, 25,
                                                      24, 25, 26, 27, 28, 29,
                                                      28, 29, 30, 31, 32, 1 };

/********************** Permutation Table   *******************/
const unsigned char PermutationTable[32] = { 16, 7, 20, 21,
                                            29, 12, 28, 17,
                                            1, 15, 23, 26,
                                            5, 18, 31, 10,
                                            2, 8, 24, 14,
                                            32, 27, 3, 9,
                                            19, 13, 30, 6,
                                            22, 11, 4, 25 };

/********************** S-box Table ***************************/
const unsigned char S_BoxTable[512] ={14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
                                      0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
                                      4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
                                      15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13,

                                      15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
                                      3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
                                      0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
                                      13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9,

                                      10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
                                      13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
                                      13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
                                      1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12,

                                      7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
                                      13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
                                      10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
                                      3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14,

                                      2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
                                      14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
                                      4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
                                      11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3,

                                      12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
                                      10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
                                      9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
                                      4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13,

                                      4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
                                      13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
                                      1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
                                      6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12,

                                      13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
                                      1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
                                      7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
                                      2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11};

/***********************    Key Tables   **************************/
/******************************************************************/

/************    Permutation Choice 1 Table   *****************/
const unsigned char PermutationChoice1Table [56] = { 57, 49, 41, 33, 25, 17, 9,
                                                    1, 58, 50, 42, 34, 26, 18,
                                                    10, 2, 59, 51, 43, 35, 27,
                                                    19, 11, 3, 60, 52, 44, 36,
                                                    63, 55, 47, 39, 31, 23, 15,
                                                    7, 62, 54, 46, 38, 30, 22,
                                                    14, 6, 61, 53, 45, 37, 29,
                                                    21, 13, 5, 28, 20, 12, 4 };


/************    Permutation Choice 2 Table   *************/
const unsigned char PermutationChoice2Table [48] = { 14, 17, 11, 24, 1, 5,
                                                    3, 28, 15, 6, 21, 10,
                                                    23, 19, 12, 4, 26, 8,
                                                    16, 7, 27, 20, 13, 2,
                                                    41, 52, 31, 37, 47, 55,
                                                    30, 40, 51, 45, 33, 48,
                                                    44, 49, 39, 56, 34, 53,
                                                    46, 42, 50, 36, 29, 32 };

/***************    Left Shift Round Table   **************/
const unsigned char LeftShiftRoundTable[16] = { 1, 1, 2, 2, 2, 2, 2, 2,
                                                1, 2, 2, 2, 2, 2, 2, 1 };

/******************************************************************************************/
/******************************   Bit Manipulations  **************************************/
/******************************************************************************************/

#define GET_BIT(VAR, X)     (((VAR >> X) & (unsigned long long) 1))
#define SET_BIT(VAR, X)     ((VAR = VAR | ((unsigned long long)1 << X))
#define CLR_BIT(VAR, X)     (VAR = VAR & (~((unsigned long long)1 << X)))


/******************************************************************************************/
/************************   Global Variables & Prototypes  ********************************/
/******************************************************************************************/

unsigned char RoundNumber = 0;
unsigned long long Keys48[16] = { 0 };

unsigned long long Permute(const unsigned long long Copy_Variable, const unsigned char* PermutateTable, unsigned char Length, unsigned char Orignial_Length);
unsigned long long LeftCircularShift(unsigned long long Copy_Variable);
void SingleRound(unsigned long long& Copy_UpperVariable, unsigned long long& Copy_LowerVariable);
unsigned long long S_BoxSubstitute(const unsigned long long Copy_Variable);
unsigned long long  Swap(const unsigned long long Copy_UpperVariable, const unsigned long long Copy_LowerVariable);
unsigned long long hex2int(const char* HexaString);

/******************************************************************************************/
/**********************************   Functions  ******************************************/
/******************************************************************************************/

int main(int argc, char* argv[])
{
    char * OperationStr = argv[1];
    char * Text64Str = argv[2];
    char * Key64Str = argv[3];

    bool OperationDecrypt = (OperationStr[0] == 'd');

    // Convert the Text from String to Integer
    unsigned long long RootText64 = 0;
    RootText64 = hex2int(Text64Str);
    
    // Convert the Key from String to Integer
    unsigned long long RootKey64;
    RootKey64 = hex2int(Key64Str);

    // Permutation Choice 1 for Key
    unsigned long long RootKey56 = Permute(RootKey64, PermutationChoice1Table, 56, 64);

    // Generate Keys
    for (RoundNumber = 0; RoundNumber < 16; RoundNumber++)
    {
        RootKey56 = LeftCircularShift(RootKey56);
        Keys48[RoundNumber] = Permute(RootKey56, PermutationChoice2Table, 48, 56);
    }

    // Invert Keys order in case of decrypt
    if (OperationDecrypt)
    {
        unsigned char i = 0;
        unsigned char j = 15;
        while (i < j) 
        {
            unsigned long long temp = Keys48[i];
            Keys48[i] = Keys48[j];
            Keys48[j] = temp;
            i++;
            j--;
        }
    }

    // Start Timer
    unsigned long long t1 = __rdtsc();

    // Initial Permutation for Text
    RootText64 = Permute(RootText64, InitialPermutationTable, 64, 64);

    // Start of 16 Rounds
    RoundNumber = 0;

    unsigned long long Upper = RootText64 >> 32;
    unsigned long long Lower = RootText64 & 0xffffffff;

    for (RoundNumber = 0; RoundNumber < 16; RoundNumber++)
    {
        SingleRound(Upper, Lower);
    }
    // Swap for Text
    unsigned long long FinalText64 = Swap(Upper, Lower);

    // Inverse Initial Permutation for Text
    FinalText64 = Permute(FinalText64, InverseInitialPermutationTable, 64, 64);

    // Stop Timer
    unsigned long long t2 = __rdtsc();

    // Print Result
    if (!OperationDecrypt)
    {
        printf("cipher: %016llX\n", FinalText64);
    }
    else
    {
        printf("plain: %016llX\n", FinalText64);
    }

    // Print Cycles
    printf("Cycles: %lld\n", t2 - t1);
}

unsigned long long  S_BoxSubstitute(const unsigned long long Copy_Variable)
{
    unsigned long long Local_ReturnVariable = 0;
    unsigned long long idx = 0;
    const unsigned char* box;
    for (unsigned char i = 0; i < 8; i++)
    {
        // Fetch the Current S-box
        box = S_BoxTable + (i * 64); 

        // Get the index
        idx = Copy_Variable >> ((7 - i) * 6) & 0x3F; 

        // Reorder bits
        idx = (idx >> 1 & 0xf) | (idx & 0x1) << 4 | (idx & 0x20); 
        Local_ReturnVariable |= (unsigned long long) box[idx] << ((7 - i) * 4);
    }
    return Local_ReturnVariable & 0xffffffff;
}

unsigned long long  Swap(const unsigned long long Copy_UpperVariable, const unsigned long long Copy_LowerVariable)
{
    unsigned long long Local_ReturnVariable = 0;
    Local_ReturnVariable = Copy_UpperVariable | (Copy_LowerVariable << 32);
    return Local_ReturnVariable;
}

void SingleRound(unsigned long long& Copy_UpperVariable, unsigned long long& Copy_LowerVariable)
{
    // Get Future Upper
    unsigned long long FutureUpper = Copy_LowerVariable;

    // Expansion Permutation for Future Lower Text
    Copy_LowerVariable = Permute(Copy_LowerVariable, ExpansionPermutationTable, 48, 32);

    // XOR Future Lower Text with Key
    Copy_LowerVariable = Copy_LowerVariable ^ Keys48[RoundNumber];

    // S-Box for Future Lower Text
    Copy_LowerVariable = S_BoxSubstitute(Copy_LowerVariable);

    // Permutation for Future Lower Text
    Copy_LowerVariable = Permute(Copy_LowerVariable, PermutationTable, 32, 32);

    // XOR Future Lower Text with Previous Upper 
    Copy_LowerVariable = Copy_LowerVariable ^ Copy_UpperVariable;

    Copy_UpperVariable = FutureUpper;
}


unsigned long long LeftCircularShift(unsigned long long Copy_Variable)
{
    for (unsigned char i = 0; i < LeftShiftRoundTable[RoundNumber]; i++)
    {
        Copy_Variable = ((Copy_Variable << 1) & 0xfffffffefffffff) | ((Copy_Variable & 0x80000008000000) >> 27);
    }
    return Copy_Variable;
}

unsigned long long Permute(const unsigned long long Copy_Variable, const unsigned char* PermutateTable, unsigned char Length, unsigned char Orignial_Length)
{
    unsigned long long Local_ReturnVariable = 0;
    for (unsigned char i = 0; i < Length; i++)
    {
        Local_ReturnVariable |= (Copy_Variable >> (Orignial_Length - PermutateTable[i]) & 1) << (Length - (i + 1));
    }
    return Local_ReturnVariable;
}


unsigned long long hex2int(const char * HexaString)
{
    unsigned long long Local_ReturnVariable = 0;
    for (;; ++HexaString)
    {
        unsigned char dec = *HexaString - '0';
        if(dec<10)
        {
            Local_ReturnVariable = Local_ReturnVariable << 4 | dec;
        }
        else
        {
            unsigned char upper = (*HexaString & 0xDF) - 'A';
            if (upper>5)
            {
                break;
            }
            Local_ReturnVariable = Local_ReturnVariable << 4 | (unsigned long long) upper + 10;
        }
    }
    return Local_ReturnVariable;
}