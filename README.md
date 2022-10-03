# Security-Market-Simulation

Assignment from "UCB MFE C++ Preprogram"

Simulate a market where 3 agents decide whether to buy or sell securities based on their
own individual decision-making processes and calculate net by summing each agent’s
individual trading amount.

Define three different heuristics that must be implement in Agent class
The NoiseAgent represents random buying and selling in the market.
The TrendAgent looks at its previously-observed price and buys if the previous price is lower
than the current price and sells if the previous price is higher.
The ValueAgent sells when its index is positive(over-valued) and buys when its index is negative(under-valued).

Simulate a market for the securities using the pseudocode.
For each period in the simulation, the dealer keeps track of the price at
the beginning of the period and updates net as it calls each agent.
