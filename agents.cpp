#include <cmath>
#include <random>
#include "agents.h"


default_random_engine generator;
auto unif=uniform_real_distribution<double>(0.0,1.0);
auto dist=normal_distribution<double>(0.0,1.0);


Agent::Agent(double tradeProb, double tradeScale):tradeProb(tradeProb),tradeScale(tradeScale){}

Dealer::Dealer(double priceScale):priceScale(priceScale){}
Dealer::~Dealer(){}

void Dealer::addAgent(Agent* a)
{
    agents.push_back(a);
}
void Dealer::runSimulation(int numSimulations, int numPeriods,vector< Result > & simResults)
{
    simResults.clear();
    for(int i= 1;i<=numSimulations;i++)
    {
        for(auto a:agents)
        {
            a->reset();
        }
        double price = 1;
        double net = 0;
        Result start(i,0,1);
        simResults.push_back(start);
        for (int j=1;j<=numPeriods;j++)
        {
            for(auto a:agents)
            {
                double u=unif(generator);
                if(u< a->tradeProb)
                {
                    net=net+a->tick(price);
                }
            }
            price=getPrice(net);
            Result result(i,j,price);
            simResults.push_back(result);
        }
    }
}
double Dealer::getPrice(double net)
{
    double price=exp(priceScale*net);
    return price;
}


double ValueAgent::tick(double price)
{
    double netToTrade = tradeScale*(-0.5+(1.0/(2.0+log(price))));
    return netToTrade;
}

double TrendAgent::tick(double price)
{
    double netToTrade = tradeScale*(log(price)-log(prevPrice));
    prevPrice = price;
    return netToTrade;
}
void  TrendAgent::reset()
{
    Agent::reset();
    prevPrice=1;
}

double NoiseAgent::tick(double price)
{
    double d=dist(generator);
    double netToTrade =d*tradeScale;
    return netToTrade;
}
