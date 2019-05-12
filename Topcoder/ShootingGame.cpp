class ShootingGame {
  public:
	double findProbability(int p) {
        if (p > 5e5) return 1.0;
        return 1.0 * p / (1e6 - p);
	}
};