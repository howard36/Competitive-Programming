#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast")
int state[10], handFreq[10], backpack[10005], stripe[100005], tempState[10];
char tempStripe[100005], tempBackpack[10004];
int N = 100000, S = 10000, C = 10, H = 10, U = 10;
double w[10] = {1.000000, 0.962219, 0.929341, 0.775924, 0.527500, 0.410121, 0.346357, 0.243525, 0.238303, 0.232648};
// double w[10] = {1.000000, 0.927803, 0.927695, 0.898510, 0.527500, 0.361100, 0.286387, 0.284520, 0.225865, 0.223394};
// double w[10] = {1.000000, 0.972703, 0.958974, 0.802141, 0.527500, 0.365624, 0.312658, 0.275641, 0.265864, 0.229064};
// double w[10] = {1.000000, 0.982654, 0.980351, 0.857861, 0.527500, 0.354073, 0.250142, 0.199266, 0.167594, 0.167412};
// double w[10] = {10.0, 9.0, 8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0};
int backpackData[10010][200], stripeData[100005][200];

/*
1.000000, 0.826389, 0.791221, 0.568768, 0.534942, 0.388035, 0.312703, 0.244658, 0.189500, 0.167829, 33109.070000, 500
1.000000, 0.995044, 0.867313, 0.806020, 0.584970, 0.504920, 0.359415, 0.348971, 0.321527, 0.226899, 33081.252000, 500
1.000000, 0.860867, 0.785225, 0.674825, 0.534113, 0.345299, 0.256208, 0.238620, 0.234542, 0.220481, 33169.096000, 500
1.000000, 0.940333, 0.906415, 0.614168, 0.520052, 0.370184, 0.305846, 0.292896, 0.189377, 0.178648, 33165.160000, 500
1.000000, 0.929328, 0.815377, 0.761360, 0.472997, 0.385123, 0.330512, 0.280812, 0.252994, 0.230802, 33164.544000, 500 (untested)
1.000000, 0.951785, 0.757621, 0.675290, 0.623563, 0.430573, 0.285766, 0.237284, 0.170746, 0.168388, 33147.018000, 500 (untested)
1.000000, 0.885142, 0.836124, 0.565674, 0.534475, 0.385359, 0.314576, 0.258259, 0.237713, 0.228855, 33137.252000, 500 (untested)
1.000000, 0.943320, 0.935830, 0.806504, 0.487358, 0.361652, 0.254237, 0.215076, 0.202344, 0.133487, 33134.514000, 500 (untested)
1.000000, 0.936836, 0.866054, 0.717417, 0.492664, 0.322244, 0.297324, 0.205557, 0.182041, 0.133733, 33116.354000, 500 (untested)
1.000000, 0.942705, 0.911531, 0.796195, 0.600993, 0.502629, 0.307949, 0.262582, 0.248699, 0.206271, 33125.766000, 500 (untested)
1.000000, 0.976593, 0.835045, 0.759134, 0.457725, 0.321984, 0.259962, 0.204008, 0.183945, 0.173797, 33125.268000, 500 (untested)
1.000000, 0.970604, 0.905289, 0.800658, 0.526502, 0.382519, 0.254779, 0.226362, 0.170406, 0.142178, 33123.282000, 500 (untested) 
1.000000, 0.977742, 0.843169, 0.755263, 0.527500, 0.335294, 0.248907, 0.220685, 0.212821, 0.193926, 33191.812000, 500
1.000000, 0.982654, 0.980351, 0.857861, 0.527500, 0.354073, 0.250142, 0.199266, 0.167594, 0.167412, 33184.698000, 500
1.000000, 0.994540, 0.946509, 0.924175, 0.527500, 0.357953, 0.356838, 0.255647, 0.248400, 0.185063, 33178.202000, 500 (untested)
1.000000, 0.947585, 0.842075, 0.785455, 0.527500, 0.373019, 0.243395, 0.236214, 0.194726, 0.172608, 33177.802000, 500 (untested)
1.000000, 0.999971, 0.921942, 0.768099, 0.527500, 0.495155, 0.352580, 0.250553, 0.240927, 0.216592, 33175.544000, 500 (untested)
1.000000, 0.842079, 0.807896, 0.732874, 0.527500, 0.418203, 0.324692, 0.238613, 0.236670, 0.234244, 33167.142000, 500 (untested)
1.000000, 0.917066, 0.863095, 0.750839, 0.527500, 0.371551, 0.337093, 0.271968, 0.248607, 0.188918, 33166.034000, 500 (untested)
1.000000, 0.995910, 0.831318, 0.802298, 0.527500, 0.513575, 0.333689, 0.279179, 0.254837, 0.247583, 33161.608000, 500 (untested)
1.000000, 0.925988, 0.851980, 0.827659, 0.527500, 0.329659, 0.304376, 0.186194, 0.166700, 0.166551, 33157.932000, 500 (untested)
1.000000, 0.856381, 0.855825, 0.846611, 0.527500, 0.458398, 0.334307, 0.305421, 0.228827, 0.226424, 33156.260000, 500 (untested)
1.000000, 0.918795, 0.864907, 0.796679, 0.527500, 0.432904, 0.343664, 0.220259, 0.198502, 0.189895, 33164.453500, 2000
1.000000, 0.962219, 0.929341, 0.775924, 0.527500, 0.410121, 0.346357, 0.243525, 0.238303, 0.232648, 33190.994500, 2000 (high)
1.000000, 0.972703, 0.958974, 0.802141, 0.527500, 0.365624, 0.312658, 0.275641, 0.265864, 0.229064, 33181.384000, 2000
1.000000, 0.910773, 0.762478, 0.745034, 0.527500, 0.327191, 0.300926, 0.234993, 0.229054, 0.223218, 33172.771000, 2000
1.000000, 0.967548, 0.895890, 0.893894, 0.527500, 0.352290, 0.301649, 0.221816, 0.192679, 0.164274, 33168.915500, 2000
1.000000, 0.872198, 0.835345, 0.807742, 0.527500, 0.357625, 0.271789, 0.219157, 0.207459, 0.177658, 33165.861000, 2000
1.000000, 0.911207, 0.859923, 0.822440, 0.527500, 0.391341, 0.308764, 0.283065, 0.249871, 0.209557, 33160.174000, 2000
1.000000, 0.927803, 0.927695, 0.898510, 0.527500, 0.361100, 0.286387, 0.284520, 0.225865, 0.223394, 33187.446000, 2000 (high)
1.000000, 0.991447, 0.914131, 0.785813, 0.527500, 0.379225, 0.343064, 0.271666, 0.226283, 0.192489, 33167.347000, 2000
1.000000, 0.948073, 0.942847, 0.849823, 0.527500, 0.367116, 0.240979, 0.218866, 0.205875, 0.170760, 33166.511500, 2000
1.000000, 0.963485, 0.918366, 0.892635, 0.527500, 0.342689, 0.221400, 0.219345, 0.194275, 0.194152, 33163.944000, 2000
1.000000, 0.966464, 0.928033, 0.889269, 0.527500, 0.320784, 0.300757, 0.298416, 0.240952, 0.195000, 33163.878000, 2000
1.000000, 0.985833, 0.983086, 0.675977, 0.527500, 0.436714, 0.305610, 0.273774, 0.212335, 0.193535, 33162.759500, 2000
*/

bool occupied(int i) {
    for (int j = 0; j<U; j++){
        if (i == state[j])
            return true;
    }
    return false;
}

int next(int u, int c){
    int i = state[u] + 1;
    while (stripe[i%N] != c || occupied(i)) {
        i++;
    }
    return i;
}

double f1(){
    double sum = 0;
    for (int i = 0; i<U; i++){
        sum += tempState[i];
    }
    return sum;
}

double f2(){
    double s = 0;
    for (int i = 0; i<U; i++){
        s += tempState[i]+1;
    }
    double sum = 0;
    for (int i = 0; i<U; i++){
        sum += (10-i)*pow((tempState[i]+1.0), -1);
    }
    return 1/sum;
}

double f3(){
    return tempState[0];
}

double f4(){
    double sum = 0;
    for (int i = 0; i<U; i++){
        sum += (10.0-i)*tempState[i];
    }
    return sum;
}

double fw(){
    double sum = 0;
    for (int i = 0; i<U; i++){
        sum += w[i]*tempState[i];
    }
    return sum;
}

double f(int i){
    for (int i = 0; i<U; i++){
        tempState[i] = state[i];
    }
    sort(tempState, tempState+U);
    // if (i < S - 10)
    //     return fw();
    return fw();
}

double test(int t){
    for (int i = 0; i<U; i++){
        state[i] = i;
    }
    memset(handFreq, 0, sizeof(handFreq));
    for (int i = 0; i<H; i++){
        handFreq[backpackData[i][t]]++;
    }
    for (int i = 0; i<N; i++){
        stripe[i] = stripeData[i][t];
    }
    
    for (int i = H; i<H+S; i++){
        backpack[i-H] = backpackData[i][t];
    }
    for (int i = 0; i<S; i++){
        double bestF = -1e9;
        int bestu = 0, bestc = 0;
        for (int c=0; c<C; c++){
            if (handFreq[c]){
                for (int u = 0; u<U; u++){
                    int temp = state[u];
                    state[u] = next(u, c);
                    double F = f(i);
                    if (F > bestF){
                        bestF = F;
                        bestu = u;
                        bestc = c;
                    }
                    state[u] = temp;
                }
            }
        }
        state[bestu] = next(bestu, bestc);
        handFreq[bestc]--;
        handFreq[backpack[i]]++;
    }
    sort(state, state+U);
    return state[0];
}

void evaluate(vector<double> &W, int n){
    for (int i = 0; i<U; i++){
        w[i] = W[i];
    }
    double sum = 0;
    for (int i = 0; i<n; i++){
        sum += test(i);
    }
    W[U] = sum/n;
}

bool comp(vector<double> a, vector<double> b){
    return a[U] > b[U];
}
/*
int main() {
    srand(time(NULL));
    for (int i = 0; i<2000; i++){
        for (int j = 0; j<N; j++){
            stripeData[j][i] = rand() % 10;
        }
        for (int j = 0; j<H+S; j++){
            backpackData[j][i] = rand() % 10;
        }
    }
    printf("Data Generated\n");
    vector<vector<double> > best;
    while (true){
        vector<double> W;
        W.push_back(1);
        for (int i = 1; i<3; i++){
            double x = (double)rand()/RAND_MAX;
            W.push_back(W[i-1]*(0.1*x+0.9));
        }
        for (int i = 3; i<4; i++){
            double x = (double)rand()/RAND_MAX;
            W.push_back(W[i-1]*(0.4*x+0.6));
        }
        W.push_back(0.5275);
        for (int i = 5; i<6; i++){
            double x = (double)rand()/RAND_MAX;
            W.push_back(W[i-1]*(0.5*x+0.5));
        }
        for (int i = 6; i<U; i++){
            double x = (double)rand()/RAND_MAX;
            W.push_back(W[i-1]*(0.4*x+0.6));
        }
        W.push_back(0);
        evaluate(W, 20);
        printf("%lf\n", W[U]);
        if (W[U] > 33120){
            evaluate(W, 200);
            printf("More accurate: %lf\n", W[U]);
            if (W[U] > 33160){
                evaluate(W, 2000);
                printf("Even more accurate: %lf\n", W[U]);
            }
        }
        if (best.size() < 10 || W[U] > best[9][U]){
            best.push_back(W);
            sort(best.begin(), best.end(), comp);
            if (best.size() > 10)
                best.pop_back();
            for (int j = 0; j<best.size(); j++){
                printf("Best[%d]: ", j);
                for (int i = 0; i<=U; i++){
                    printf(" %lf,", best[j][i]);
                }
                printf("\n");
            }
        }
    }
}
*/

int main() {
    // freopen("data.txt", "r", stdin);
    scanf("%d%d%d%d%d", &N, &S, &C, &H, &U);
    for (int i = 0; i<U; i++){
        state[i] = i;
    }
    scanf("%s", tempStripe);
    for (int i = 0; i<N; i++){
        stripe[i] = tempStripe[i] - 'A';
    }
    scanf("%s", tempBackpack);
    for (int i = 0; i<H; i++){
        handFreq[tempBackpack[i]-'A']++;
    }
    for (int i = H; i<H+S; i++){
        backpack[i-H] = tempBackpack[i]-'A';
    }
    for (int i = 0; i<S; i++){
        double bestF = -1e9;
        int bestu = 0, bestc = 0;
        for (int c1=0; c1<C; c1++){
            if (handFreq[c1]){
                handFreq[c1]--;
                for (int u1 = 0; u1<U; u1++){
                    int temp1 = state[u1];
                    state[u1] = next(u1, c1);
                    double F = -1e9;
                    if (i == S-1) { // last move
                        F = f(i);
                    }
                    else {
                        for (int c2=0; c2<C; c2++){
                            if (handFreq[c2]){
                                for (int u2 = 0; u2<U; u2++){
                                    int temp2 = state[u2];
                                    state[u2] = next(u2, c2);
                                    F = max(F, f(i+1));
                                    state[u2] = temp2;
                                }
                            }
                        }
                    }
                    if (F > bestF){
                        bestF = F;
                        bestu = u1;
                        bestc = c1;
                    }
                    state[u1] = temp1;
                }
                handFreq[c1]++;
            }
        }
        state[bestu] = next(bestu, bestc);
        handFreq[bestc]--;
        handFreq[backpack[i]]++;
        printf("%d %c\n", bestu, 'A'+bestc);
        // printf("Chameleon %d now at %d\n", bestu, state[bestu]);
        // printf("Hand Freq: ");
        // for (int j = 0; j<C; j++){
        //     printf("%d ", handFreq[j]);
        // }
        // printf("\n");
    }
    // sort(state, state+U);
    // printf("Result: %d\n", state[0]);
}
