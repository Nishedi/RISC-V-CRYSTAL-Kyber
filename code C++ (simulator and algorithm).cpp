#include <list>
#include <iostream>
#include <bitset>
#include <limits>
#include <cmath>
#define MAXN 40960



/*void circularConvolve(int vec0[], int vec1[], int output[], int outputsize) {
    const int sizeofvec0 = sizeof(vec0) / sizeof(vec0[0]);
    const int sizeofvec1 = sizeof(vec1) / sizeof(vec1[0]);
    if (sizeofvec0 == 0 || sizeofvec0 != sizeofvec1) {
        std::cout << "Nieprawidlowe argumenty circularConvolve\n";
        return;
    }
    int maxval = 0;

    for (int i = 0; i < sizeofvec0; i++) {
        if (vec0[i] < 0)return;
        if (vec0[i] > maxval)maxval = vec0[i];
    }
    for (int i = 0; i < sizeofvec1; i++) {
        if (vec1[i] < 0)return;
        if (vec1[i] > maxval)maxval = vec1[i];
    }



    int64_t minmod = static_cast<int64_t>(std::pow(maxval, 2)) * sizeofvec0 + 1;
    if (std::numeric_limits<int>::digits < std::numeric_limits<decltype(minmod)>::digits || minmod > std::numeric_limits<int>::max()) {
        std::cout << "za duza cyfra\n";
        return;
    }
    int mod = findModulus(sizeofvec0, minmod);//podejrzane
    int root = findPrimitiveRoot(sizeofvec0, mod - 1, mod);

    int temp0[sizeofvec0]; transform(vec0, sizeofvec0, root, mod, temp0);
    int temp1[sizeofvec0]; transform(vec1, sizeofvec1, root, mod, temp1);
    int temp2[sizeofvec0];
    for (int i = 0; i < sizeofvec0; i++)
        temp2[i] = (int)((long)temp0[i] * temp1[i] % mod);


    inverseTransform(temp2, outputsize, root, mod, output);

}*/

#include <chrono>
using namespace std::chrono;
class Timer
{
    high_resolution_clock::time_point t0;
    high_resolution_clock::time_point t1;
public:
    void start() {
        t0 = high_resolution_clock::now();
    }
    void stop() {
        t1 = high_resolution_clock::now();
    }

    uint64_t timeperiod() {
        duration< double > fs = t1 - t0;
        return (uint64_t)(fs.count() * 1000000);
    }
};


class RiscV {
public:
    long v0[32];
    long v1[32];
    long v2[32];
    long v3[32];
    long v4[32];
    long v5[32];
    long v6[32];
    long v7[32];
    long x[32];
   // long* ra, *sp, *gp, *tp, *t0, *t1, *t2, *s0, *s1, *a0, *a1, *a2, *a3, *a4, *a5, *a6, *a7, *s2, *s3, *s4, *s5, *s6, *s7, *s8, *s9, *s10, *s11, *t3, *t4, *t5, *t6;
    long ra, sp, gp, tp, t0, t1, t2, s0, s1, a0, a1, a2, a3, a4, a5, a6, a7, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, t3, t4, t5, t6;
public:
    RiscV() {
       /* x[0] = 0;
        ra = x+1;
        sp = x + 2;
        gp = x + 3;
        tp = x + 4;
        t0 = x + 5;
        t1 = x + 6;
        t2 = x + 7;
        s0 = x + 8;
        s1 = x + 9;
        a0 = x + 10;
        a1 = x + 11;
        a2 = x + 12;
        a3 = x + 13;
        a4 = x + 14;
        a5 = x + 15;
        a6 = x + 16;
        a7 = x + 17;
        s2 = x + 18;
        s3 = x + 19;
        s4 = x + 20;
        s5 = x + 21;
        s6 = x + 22;
        s7 = x + 23;
        s8 = x + 24;
        s9 = x + 25;
        s10 = x + 26;
        s11 = x + 27;
        t3 = x + 28;
        t4 = x + 29;
        t5 = x + 30;
        t6 = x + 31;*/
    }

    void vlpolye32(long G[], int memory[], int vm) {
        for (int m = 0; m < vm; m++) {
            G[m] = memory[m];
        }
    }

    void vspolye32(long G[], int memory[], int vm) {
        for (int m = 0; m < vm; m++) {
            memory[m] = G[m];
        }
    }
    
    void vsetvli(long rd, long rs1, long imm) {

    }
    //Vector indexed loads
    void vlxwu_v(long vd[], long rs1[],  long vs2[], int vm) {
        for (a3 = 0; a3 < vm; a3++) {
            vd[a3] = rs1[vs2[a3]];
        }
    }
   
    //Vector ordered-indexed store instructions
    void vsxw_v(long vs3[], long rs1[],  long vs2[], int vm) {
        for (a3 = 0; a3 < vm; a3++) {
            vs3[vs2[a3]] = rs1[a3];
        }
    }
       
    //Integer adds.
    void vadd_vv(long vd[], long vs2[], long vs1[],  int vm) {
        for (a3 = 0; a3 < vm; a3++) {
            vd[a3] = vs2[a3] + vs1[a3];
        }
    }
   
    //Integer subtract 
    void vsub_vv(long vd[], long vs2[], long vs1[],  int vm) {
        for (a3 = 0; a3 < vm; a3++) {
            vd[a3] = vs2[a3] - vs1[a3];
        }
    }

    //Signed multiply, returning low bits of product
    void vmul_vv(long vd[], long vs2[], long vs1[],  int vm) {
        for (a3 = 0; a3 < vm; a3++) {
            vd[a3] = vs2[a3] * vs1[a3] ;
        }
    }

    //Unsigner remainder - vector - scalar
    void vremu_vx(long vd[], long vs2[], int rs1, int vm) {
        for (a3 = 0; a3 < vm; a3++) {
            vd[a3]=(vs2[a3]+rs1) % rs1;
        }
    }


    void NTT(int vector[], int n , int levels, int _j[], int _jm[],int _k[], int powTable[], int mod) {
        
        vlpolye32(v0, vector, n); //v0 wektor
        for (t3 = levels; t3 >0; t3--) {
            int offset = (levels - t3) * n / 2;
            vlpolye32(v2, _jm + offset, n / 2);//v2 = _jm 
            vlxwu_v(v5, v0, v2, n / 2); //v5 = b1 = vector[jm]
            vlpolye32(v1, _k + offset, n / 2);//G4 = k = _k[iter]
            vlpolye32(v4, powTable, n / 2);//v6 = powertable
            vlxwu_v(v7, v4, v1, n / 2);//v1 = powertable[k]          
            vmul_vv(v5, v5, v7, n / 2);
            vremu_vx(v5, v5, mod, n / 2);
            vlpolye32(v7, _j + offset, n / 2); //v1 indeksy j
            vlxwu_v(v3, v0, v7, n / 2);//v4 = a = vector[j]
            vadd_vv(v4, v3, v5, n / 2);//v4=(a+b)%mod
            vremu_vx(v4, v4, mod, n / 2);
            vsxw_v(v0, v4, v7, n / 2);
            vsub_vv(v4, v3, v5, n / 2);//v4=(a-b)%mod
            vremu_vx(v4, v4, mod, n / 2);
            vsxw_v(v0, v4, v2, n / 2);
        }
        vspolye32(v0, vector, n); 
    }
};

class NTTDesine {
//public:
   

    int findMax(int vec[], int n) {
        int maxVal = 0;
        for (int j = 0; j < n; j++) {
            if (vec[j] > maxVal)maxVal = vec[j];
        }
        return maxVal;
    }

    int maximum(int tab[], int size) {
        int max = 0;
        for (int i = 0; i < size; i++) {
            if (max < tab[i])max = tab[i];
        }
        return max;
    }

    bool isPrime(int n) {
        if (n <= 1) {
            std::cout << "Is prime - nieprawidlowy argument\n";
            return false;
        }
        for (int i = 2, end = sqrt(n); i <= end; i++) {

            if (n % i == 0)
                return false;
        }
        return true;
    }

    void uniquePrimeFactors(int n, std::list<int>& result) {
        if (n < 1) {
            std::cout << "Niewlasciwe argumenty uniquePrimefactors\n";
            return;
        }

        for (int i = 2, end = sqrt(n); i <= end; i++) {
            if (n % i == 0) {
                result.push_front(i);
                do n /= i;
                while (n % i == 0);
                end = sqrt(n);
            }
        }
        if (n > 1)
            result.push_front(n);
    }

    int isPrimitiveRoot(int val, int degree, int mod) {
        if (val < 0 || val >= mod) {
            std::cout << "Niewlasciwe argumenty isPrimitiveRoot\n";
            return -1;
        }
        if (degree < 1 || degree >= mod) {
            std::cout << "Niewlasciwe argumenty isPrimitiveRoot\n";
            return -1;
        }
        if (pow(val, degree, mod) != 1)
            return false;

        std::list<int> lista;
        uniquePrimeFactors(degree, lista);
        for (int p : lista) {
            if (pow(val, degree / p, mod) == 1)
                return false;
        }
        return true;
    }

    int findGenerator(int totient, int mod) {
        if (totient < 1 || totient >= mod) {
            std::cout << "Nieprawidlowe argumenty generator\n";
            return -1;
        }
        for (int i = 1; i < mod; i++) {
            if (isPrimitiveRoot(i, totient, mod))
                return i;
        }
        std::cout << "Brak generatora\n";
        return -1;
    }

    int pow(int x, int y, int mod) {
        if (x < 0 || x >= mod || y < 0) {
            std::cout << "Niewlasciwe argumenty pow\n";
        }

        int result = 1;
        for (; y != 0; y >>= 1) {
            if ((y & 1) != 0)
                result = ((long long)result * x) % mod;
            x = ((long long)x * x) % mod;
        }
        return result;
    }   

    

    public:
    int findModulus(int vector[], int n) {
        int maximum = findMax(vector, n);
        if (n < 1 || maximum < 1) {
            std::cout << "zle argumenty findModules\n";
            return -1;
        }
        int start = (int)((long)(maximum - 1 + n - 1) / n);
        if (start < 1)
           start = 1;

        for (long i = (long)start * n + 1; i <= std::numeric_limits<int>::max(); i += n) {
            if (isPrime((int)i) == true) {
                return (int)i;
            }
        }
        return -1;
    }

    int reciprocal(int n, int mod) {
        if (n < 0 || n >= mod) {
            std::cout << "Niewlasciwe argumenty reciprocal\n";
        }
        int x = mod;
        int y = n;
        int a = 0;
        int b = 1;
        while (y != 0) {
            int temp = a - x / y * b;
            a = b;
            b = temp;
            temp = x % y;
            x = y;
            y = temp;
        }
        if (x == 1)
            return a >= 0 ? a : a + mod;
        else {
            std::cout << "Blad arytmetyczny reciprocal\n";
        }
    }
    
    int findPrimitiveRoot(int totient, int mod, int n) {
        if (n< 1 || n > totient || totient >= mod || totient % n != 0) {
            std::cout << "Niewlasciwie argumenty findPrimitiveRoot\n";
            return -1;
        }
        int gen = findGenerator(totient, mod);
        return pow(gen, totient / n, mod);
    }

};

class NTT {
public:
    int n;
    
    int  *output;
    int mod;
    int root;
    int reprocal;
   
    NTT(int n, int root, int mod, int reprocal) {
        this->n = n;
        this->root = root;
        this->mod = mod;
        this->output = new int[n];
        this->reprocal=reprocal;
    }

    ~NTT() {
        delete[] output;
    }

    int pow(int x, int y, int mod) {
        if (x < 0 || x >= mod || y < 0) {
            std::cout << "Niewlasciwe argumenty pow\n";
        }

        int result = 1;
        for (; y != 0; y >>= 1) {
            if ((y & 1) != 0)
                result = ((long long)result * x) % mod;
            x = ((long long)x * x) % mod;
        }
        return result;
    }

    int reciprocal(int n, int mod) {
        if (n < 0 || n >= mod) {
            std::cout << "Niewlasciwe argumenty reciprocal\n";
        }
        int x = mod;
        int y = n;
        int a = 0;
        int b = 1;
        while (y != 0) {
            int temp = a - x / y * b;
            a = b;
            b = temp;
            temp = x % y;
            x = y;
            y = temp;
        }
        if (x == 1)
            return a >= 0 ? a : a + mod;
        else {
            std::cout << "Blad arytmetyczny reciprocal\n";
        }
    }  

    virtual void transform(int v[], int root) {
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                int k = (int)((long)i * j % n);
                long temp = (long)v[j] * pow(root, k, mod) + sum;
                sum = (int)(temp % mod);
            }
            output[i] = sum;
        }
        for (int i = 0; i < n; i++) {
            v[i] = output[i];
        }

    }

    virtual void inverseTransform(int v[], int root) {
        transform(v, reprocal);
        int scaler = reciprocal(n, mod);
        for (int i = 0; i < n; i++) {
            v[i] = (int)((long)v[i] * scaler % mod);
        }
    }

};

class FastNTT : public NTT {
public:
    int* powTable;
    int* powTableReverse;

    FastNTT(int n, int root, int mod, int reprocal) :NTT(n, root, mod, reprocal) {
        powTable = new int[n / 2];
        powTableReverse = new int[n / 2];
        createPowTable(root, mod, powTable);
        createPowTable(reprocal, mod, powTableReverse);
    }
    ~FastNTT() {
        delete[] powTable;
        delete[] powTableReverse;
    }


    int power(int number, int factor) {
        int toreturn = 1;
        for (int i = 0; i < factor; i++) {
            toreturn *= number;
        }
        return toreturn;
    }

    void bit_reverse(int v[], int output[]) {
        int num_bits = log2(n);
        int reverse_num;
        for (int i = 0; i < n; i++) {
            reverse_num = 0;
            for (int j = 0; j < num_bits; j++) {
                reverse_num = reverse_num << 1;
                if (i & (1 << j)) {
                    reverse_num = reverse_num | 1;
                }
            }
            output[reverse_num] = v[i];
        }
    }

    void createPowTable(int root, int mod, int* powTable) {
        int npow = n / 2;
        {
            int temp = 1;
            for (int i = 0; i < npow; i++) {
                powTable[i] = temp;
                temp = (int)((long)temp * root % mod);
            }
        }

    }

    void transform(int vector[], int root) {

        transform(vector, root, powTable);
    }
    virtual void inverseTransform(int v[], int root) {
        transform(v, reprocal, powTableReverse);
        int scaler = reciprocal(n, mod);
        for (int i = 0; i < n; i++) {
            v[i] = (int)((long)v[i] * scaler % mod);
        }
    }
    void transform(int vector[], int root, int* powTable) {

        int levels = static_cast<int>(std::log2(n));

        bit_reverse(vector, output);
        for (int i = 0; i < n; i++) {
            vector[i] = output[i];
        }
        int m = 1;
        for (int i = 0; i < levels; i++) {

            for (int s = 0; s < power(2, levels); s += m * 2) {
                int k = 0;
                for (int j = s; j < s + m; j++) {
                    long a = vector[j];
                    long b = (long)vector[j + m] * powTable[k] % mod;
                    vector[j] = (int)((a + b) % mod);
                    vector[j + m] = (int)((a - b + mod) % mod);
                    k += n / (m * 2);
                    //k += levels;
                }
            }
            m *= 2;
        }
    }

};

class FastNTTWektor : public NTT {
public:
    int* powTable;
    int* powTableReverse;
    int *_j;
    int *_jm;
    int *_k;
    int levels;
    

    FastNTTWektor(int n, int root, int mod, int reprocal) :NTT(n, root, mod, reprocal) {
        levels = static_cast<int>(std::log2(n));
        powTable = new int[n / 2];
        powTableReverse = new int[n / 2];
        createPowTable(root, mod, powTable);
        createPowTable(reprocal, mod, powTableReverse);
        _j = new int[n / 2 * levels];
        _jm = new int[n / 2 * levels];
        _k = new int[n / 2 * levels];

        /*for (int i = 0; i < 100; i++) {
            std::cout<<_j
        }*/
        indexing();
        
    }
    ~FastNTTWektor() {
        delete[] _j;
        delete[] _jm;
        delete[] _k;
        delete[] powTable;
        delete[] powTableReverse;
    }


    int power(int number, int factor) {
        int toreturn = 1;
        for (int i = 0; i < factor; i++) {
            toreturn *= number;
        }
        return toreturn;
    }

    void bit_reverse(int v[], int output[]) {
        int num_bits = log2(n);
        int reverse_num;
        for (int i = 0; i < n; i++) {
            reverse_num = 0;
            for (int j = 0; j < num_bits; j++) {
                reverse_num = reverse_num << 1;
                if (i & (1 << j)) {
                    reverse_num = reverse_num | 1;
                }
            }
            output[reverse_num] = v[i];
        }
    }

    void createPowTable(int root, int mod, int * powTable) {
        int npow = n / 2;
        {
            int temp = 1;
            for (int i = 0; i < npow; i++) {
                powTable[i] = temp;
                temp = (int)((long)temp * root % mod);
            }
        }

    }

    void transform(int vector[], int root) {

        transform(vector, root, powTable);
    }
    virtual void inverseTransform(int v[], int root) {
        transform(v, reprocal, powTableReverse);
        int scaler = reciprocal(n, mod);
        for (int i = 0; i < n; i++) {
            v[i] = (int)((long)v[i] * scaler % mod);
        }
    }

    void print(int vec[], int n) {
        for (int i = 0; i < n; i++) {
            std::cout << vec[i]<<" ";
        }
        std::cout << "\n";
    }

    void transform(int vector[], int root, int* powTable) { 
        RiscV riscV;
        int iter = 0;
        int s = 1;
        bit_reverse(vector, output);
        for (int i = 0; i < n; i++) {
            vector[i] = output[i];
        }
        riscV.NTT(vector, n, levels, _j, _jm, _k, powTable, mod);
        
    }
   
    void indexing() {
        int iter = 0;
        int levels = static_cast<int>(std::log2(n));
        int m = 1;
        for (int i = 0; i < levels; i++) {  
            for (int s = 0; s < power(2, levels); s += m * 2) {
                int k = 0;
                for (int j = s; j < s + m; j++) {
                    _j[iter] = j;
                    _jm[iter] = j + m;
                    _k[iter] = k;
                    iter++;
                    k += n / (m * 2);
                }
            }
            m *= 2;
        }
    }
};



void generatevec(int vec[], int size) {
    for (int i = 0; i < size; i++) {
        vec[i] = rand();
    }
}

int main()
{
   /* int invec[] = {2285, 2571, 2970, 1812, 1493, 1422, 287, 202, 3158, 622, 1577, 182, 962,
                2127, 1855, 1468, 573, 2004, 264, 383, 2500, 1458, 1727, 3199, 2648, 1017,
                732, 608, 1787, 411, 3124, 1758, 1223, 652, 2777, 1015, 2036, 1491, 3047,
                1785, 516, 3321, 3009, 2663, 1711, 2167, 126, 1469, 2476, 3239, 3058, 830,
                107, 1908, 3082, 2378, 2931, 961, 1821, 2604, 448, 2264, 677, 2054, 2226,
                430, 555, 843, 2078, 871, 1550, 105, 422, 587, 177, 3094, 3038, 2869, 1574,
                1653, 3083, 778, 1159, 3182, 2552, 1483, 2727, 1119, 1739, 644, 2457, 349,
                418, 329, 3173, 3254, 817, 1097, 603, 610, 1322, 2044, 1864, 384, 2114, 3193,
                1218, 1994, 2455, 220, 2142, 1670, 2144, 1799, 2051, 794, 1819, 2475, 2459,
                478, 3221, 3021, 996, 991, 958, 1869, 1522, 1628 };

    const int size = sizeof(invec) / sizeof(invec[0]);
    int max = maximum(invec, size);
    int mod = findModulus(size, max);
    int root = findPrimitiveRoot(size, mod - 1, mod);
   

    int outvec[size];
    transform(invec, size, root, mod, outvec);
    for (int i = 0; i < size; i++) {
        std::cout << outvec[i] << " ";
    }
    std::cout << "\n\n\n";
    int returntab[size];
    inverseTransform(outvec, size, root, mod, returntab);
    for (int i = 0; i < size; i++) {
        //std::cout << returntab[i]<<" ";
        if (returntab[i] != invec[i])std::cout << "rozne \n";
    }*/
    Timer timer;
    int ex[] = { 2,2,2,2,4,16,32,64,128,256,512,1024,2048,4096 };

    for (int i = 6; i < 7; i++) {
        
        timer.start();
        int n = ex[i];
        
        NTTDesine prepare;
        /*int vec[] = {44,10,34,25,22,33,44,32,31,8, 16,
                        6,7,14,35,32,39,43,5,12, 10,
                        41,8,38,25,46,12,36,2,39, 25,
                        23 };*/
        int vec[MAXN];
        generatevec(vec, n);
        int mod = prepare.findModulus(vec,n);
        int root = prepare.findPrimitiveRoot(mod - 1, mod, n);
        int rep = prepare.reciprocal(root, mod);
        FastNTTWektor* a = new FastNTTWektor(n, root, mod, rep);
       //FastNTT *  a = new FastNTT(n, root,mod,rep);
        //NTT * a=new NTT(n, root, mod,rep);
        int copia[MAXN];
        for (int i = 0; i < n; i++) {
            copia[i] = vec[i];
        }

        a->transform(vec, root);
        int output[MAXN];
        a->inverseTransform(vec, root);
        

        for (int i = 0; i < n; i++) {
            output[i] = vec[i];
        }

        for (int j = 0; j < n; j++) {
            if (copia[j] != output[j])
            {
                std::cout << "ERROR\n";
                std::cout << copia[j] << " " << output[j] << std::endl;
            }
        }
        timer.stop();
        std::cout << timer.timeperiod() << " " << ex[i] << std::endl;
        delete a;
    }

}

