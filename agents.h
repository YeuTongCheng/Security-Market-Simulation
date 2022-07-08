#ifndef agents_h
#define agents_h
#include <vector>
using namespace std;

class Agent
{
public:
         double tradeProb;
         double tradeScale;
         
public:
         Agent(double tradeProb, double tradeScale);
         virtual ~Agent() {};
         virtual double tick(double price)=0;
         virtual void reset() {}
};

class Result
{
public:
         int sim;
         int period;
         double price;
         public:
         Result() {};
         Result(int sim, int period, double price): sim(sim), period(period), price(price) {}
};

class Dealer
{
private:
         vector<Agent*> agents;
         double priceScale;
public:
         Dealer(double priceScale);
         virtual ~Dealer();
         void addAgent(Agent* a);
         void runSimulation(int numSimulations, int numPeriods, vector< Result > & simResults);
         double getPrice(double net);
};

class ValueAgent : public Agent
{
public:
         ValueAgent(double tradeProb,double tradeScale):Agent(tradeProb, tradeScale) {}
         double tick(double price);
};

class TrendAgent : public Agent
{
protected:
         double prevPrice = 1.0;
public:
         TrendAgent(double tradeProb,double tradeScale):Agent(tradeProb, tradeScale) {}
         double tick(double price);
         void reset();
};

class NoiseAgent : public Agent
{
public:
         NoiseAgent(double tradeScale):Agent(1.0, tradeScale) {}
         double tick(double price);
};
#endif
