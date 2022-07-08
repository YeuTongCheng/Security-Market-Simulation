# Security-Market-Simulation
A market where N participants (agents) decide whether to buy or sell securities based on their
own individual heuristics (decision-making processes). Calculate net by summing each agent’s
individual trading amount.

Define three different heuristics that must be implement as derived classes of an Agent class
The NoiseAgent represents random buying and selling in the market.
The TrendAgent looks at its previously-observed price and buys if the previous price is lower
than the current price and sells if the previous price is higher.
The ValueAgent sells when its index is positive and buys when its index is negative.

Simulate a market for the securities using the pseudocode.
The caller of runSimulation() passes in a vector of Result objects in which results
will be stored. For each period in the simulation, the dealer keeps track of the price at
the beginning of the period and updates net as it calls each agent. The dealer only
updates the price after each agent’s tick() method has been called
