#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// This Solution GIVES TLE
string GetKey(int a, int b) {
    return to_string(a) + "," + to_string(b);
}

int minimumOperations(int arr[], int start, int end, int n, int x, unordered_map<string, int>& occured)
{
    string key = GetKey(start, end);

    if (occured.find(key) != occured.end()) {
        return occured[key];
    }

    if (x == 0) {
        return 0;
    }

    if (start > end || x < 0) {
        return 10e6;
    }


    int leftChoice = minimumOperations(arr, start + 1, end, n, x - arr[start], occured);
    int rightChoice = minimumOperations(arr, start, end - 1, n, x - arr[end], occured);

    // if (leftChoice == -1 && rightChoice == -1) {
    //     occured[key] = -1;
    //     return -1;
    // } else if (leftChoice == -1) {
    //     occured[key] = rightChoice + 1;
    //     return rightChoice + 1;
    // } else if (rightChoice == -1) {
    //     occured[key] = leftChoice + 1;
    //     return leftChoice + 1;
    // } else {
    //     occured[key] = min(leftChoice, rightChoice) + 1;
    //     return occured[key];
    // }

    occured[key] = min(leftChoice, rightChoice) + 1;
    return occured[key];
}

int MinimumOperations(int arr[], int n, int x)
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int requiredSum = sum - x;

    int currentSum = arr[0],
        start = 0,
        i;

    for (i = 1; i <= n; i++) {
        while (currentSum > requiredSum && start < i - 1) {
            currentSum = currentSum - arr[start];
            start++;
        }

        if (currentSum == requiredSum) {
            return i - 1 - start;
        }

        if (i < n) {
            currentSum += arr[i];
        }
    }

    return -1;
}

// Leet Code SOlution
int MinOperations(vector<int> arr, int n, int x)
{
    int tg = -x, ans = -1;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        tg += arr[i];
    }

    if (tg == 0) {
        return n;
    }

    vector<int> prefixSum(n, arr[0]);

    mp[0] = -1;
    mp[arr[0]] = 0;
    if (prefixSum[0] == tg) {
        ans = 1;
    }

    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
        if (mp.find(prefixSum[i] - tg) != mp.end()) {
            ans = max(ans, i - mp[prefixSum[i] - tg]);
        }

        mp[prefixSum[i]] = i;
    }

    return (ans == -1) ? -1 : n - ans;
}

void solution()
{
    int n, x;
    // cin >> n >> x;

    // int arr[n];
    // for (int i = 0; i < n; i++) {
    //     cin >> arr[i];
    // }

    int arr[] = {
    // 1241,8769,9151,3211,2314,8007,3713,5835,2176,8227,5251,9229,904,1899,5513,7878,8663,3804,2685,3501,1204,9742,2578,8849,1120,4687,5902,9929,6769,8171,5150,1343,9619,3973,3273,6427,47,8701,2741,7402,1412,2223,8152,805,6726,9128,2794,7137,6725,4279,7200,5582,9583,7443,6573,7221,1423,4859,2608,3772,7437,2581,975,3893,9172,3,3113,2978,9300,6029,4958,229,4630,653,1421,5512,5392,7287,8643,4495,2640,8047,7268,3878,6010,8070,7560,8931,76,6502,5952,4871,5986,4935,3015,8263,7497,8153,384,1136
        355,7447,7074,9493,5800,1102,192,3619,3791,3817,668,6342,525,7487,977,2604,8001,7641,2770,1982,3737,9955,9348,5633,4101,9101,2670,6200,1405,3594,3697,3419,3053,5184,8899,3391,6435,6598,1790,2389,9635,6011,3447,6756,8677,3085,4478,6821,8818,7262,538,5548,6128,9137,8851,6759,7709,8363,1833,8865,3383,7837,3436,5359,8232,2184,8846,9369,8692,9170,8543,7491,3402,2858,7364,5118,1726,7987,9872,2378,9642,8786,8892,8915,9521,6239,3388,3142,8742,6655,4085,6452,676,717,4619,6938,4684,6590,4959,6069,6433,6309,7963,1187,5323,8129,6631,6430,8863,646,7519,4582,6080,6293,7641,7840,6443,702,3935,7007,8148,5712,3205,8784,6909,6668,1562,8346,4439,9019,9006,5071,9140,9059,986,1915,8171,8064,6327,5784,4755,923,6692,4943,5140,7951,3423,3387,7555,104,4591,8785,7745,9928,217,1126,763,1975,1004,5539,8525,8657,3221,4507,3654,6863,8025,6687,135,1277,8067,5059,8535,5586,1390,6584,9455,3349,4852,4666,7036,9503,1041,3678,1463,4689,291,5023,1295,8634,2532,2224,1905,1680,8948,4754,5447,318,1740,2001,2111,5784,6988,6828,2338,6728,1807,7369,4723,2777,5780,3539,7307,8694,2665,8251,4867,4426,7050,2903,2983,1722,6557,960,6205,7908,7365,749,6510,6258,2357,9562,8354,9915,5185,3794,1488,808,1386,4178,2044,7189,6600,7143,8346,2329,1550,4868,5392,8918,9260,6024,3322,3540,7611,6098,2357,999,3112,5104,9863,2030,145,2055,3659,4204,4646,7411,2021,7771,8200,9513,6701,9802,4717,1488,1200,7300,4144,6199,7081,9481,1858,6457,2284,7798,5167,8116,1982,3590,657,2584,3084,5007,9606,6811,8655,2270,7793,1355,167,7400,7685,1853,7201,387,2066,1746,500,1236,4655,5088,5701,4744,2236,7425,3437,4467,5157,7134,166,7142,215,2311,399,4848,1113,6182,5780,7088,5684,3132,6459,351,5765,7537,9581,9765,7358,8794,6043,3164,4807,6551,7978,8179,3457,3593,7309,7136,1917,7929,809,4148,2327,461,827,2393,2077,5230,9245,5855,346,3750,4009,4467,8136,7777,7938,6955,1168,4911,6258,3227,1333,9799,1950,3867
        // 1, 1, 4, 2, 3
    };



    n = sizeof(arr) / sizeof(arr[0]);
    x = 218936868;
    // x = 894887480;
    // x = 5;

    unordered_map<string, int> occured;

    // int ans = minimumOperations(arr, 0, n - 1, n, x, occured);
    // cout << (ans == 10e6 ? -1 : ans) << endl;

    int ans = MinimumOperations(arr, n, x);
    if (ans == -1) {
        cout << -1 << endl; 
    } else {
        cout << n - ans << endl;
    }


}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}

/*
    int n, x;
    cin >> n >> x;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }   

    // int arr[] = {
    //     5207,5594,477,6938,8010,7606,2356,6349,3970,751,5997,6114,9903,3859,6900,7722,2378,1996,8902,228,4461,90,7321,7893,4879,9987,1146,8177,1073,7254,5088,402,4266,6443,3084,1403,5357,2565,3470,3639,9468,8932,3119,5839,8008,2712,2735,825,4236,3703,2711,530,9630,1521,2174,5027,4833,3483,445,8300,3194,8784,279,3097,1491,9864,4992,6164,2043,5364,9192,9649,9944,7230,7224,585,3722,5628,4833,8379,3967,5649,2554,5828,4331,3547,7847,5433,3394,4968,9983,3540,9224,6216,9665,8070,31,3555,4198,2626,9553,9724,4503,1951,9980,3975,6025,8928,2952,911,3674,6620,3745,6548,4985,5206,5777,1908,6029,2322,2626,2188,5639
    // };

    // n = sizeof(arr) / sizeof(arr[0]);
    // x = 565610;

    int front = 0;
    int back = n - 1;

    int count = 0;

    while (true) {
        int leftChoice = x - arr[front];
        int rightChoice = x - arr[back];

        if (leftChoice < 0 && rightChoice < 0) {
            cout << -1 << endl;
            break;
        }

        if (leftChoice < 0 && rightChoice >= 0) {
            x = rightChoice;
            back--;
        } else if (leftChoice >= 0 && rightChoice < 0) {
            x = leftChoice;
            front++;
        } else {
            if (leftChoice <= rightChoice) {
                x = leftChoice;
                front++;
            } else {
                x = rightChoice;
                back--;
            }
        }

        count++;
        printf("L: %d, R: %d X: %d Count: %d\n", leftChoice, rightChoice, x, count);

        
        if (x == 0) {
            cout << count << endl;
            break;
        }

        if (front > back) {
            cout << -1 << endl;
            break;
        }
    }
*/