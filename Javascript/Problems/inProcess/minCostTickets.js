// https://leetcode.com/problems/minimum-cost-for-tickets/
// You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

// Train tickets are sold in three different ways:

// a 1-day pass is sold for costs[0] dollars,
// a 7-day pass is sold for costs[1] dollars, and
// a 30-day pass is sold for costs[2] dollars.
// The passes allow that many days of consecutive travel.

// For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
// Return the minimum number of dollars you need to travel every day in the given list of days.

 

// Example 1:

// Input: days = [1,4,6,7,8,20], costs = [2,7,15]
// Output: 11
// Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
// On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
// On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
// On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
// In total, you spent $11 and covered all the days of your travel.
// Example 2:

// Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
// Output: 17
// Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
// On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
// On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
// In total, you spent $17 and covered all the days of your travel.




// If 1 day travel, get 1-day pass
// If 2 consec days, lessor of 2 x 1 or 7-day
// If 3 consec days, lessor of 3 x 1 or 7-day
// If days[i+1] - days[i] 
// days = [1,4,6,7,8,20]
// days[1] - days[0] = 4 - 1 - 1 = 2
// days[2] - days[1] = 6 - 4 -1 = 1

// costs = [2,7,15]
// costs[0]*4 > costs[1]; so if there are 4 consec days, cheaper to buy 7-day
// factor_0 = Math.ceil(costs[1]/costs[0]) 
// costs[1]*3 > costs[2]; if there are > 7*3 consec days, cheaper to buy 15-day
// factor_1 = Math.ceil(costs[2]/costs[1]) 



var mincostTickets = function(days, costs) {
    factor7 = Math.ceil(costs[1]/costs[0]);
    factor30 = Math.ceil(costs[2]/costs[1]);
    console.log(factor7, factor30);


};

days = [1,2,3,4,5,6,7,8,9,10,30,31];
costs = [2,7,15];
console.log(mincostTickets(days, costs));

// elemPlus7: day[i] + 7; days that 7-day is valid
// elemPlus30: day[i] + 30; days that 30-day is valid
// if there are > factor_0 elements in 7-day period, buy 7-day
// if there are > factor_1 elements in 30-day period, buy 30-day

// for (ind = 0; ind < days.length; ind++)
// for 1 day: days[0] = 1, end on day 1 (1 + 1 - 1) day+ticket-1
// => cost of all 1-day ticks = costs[0]*days.length

// for 7 day: days[0] = 1, end on day 7 (1 + 7 - 1)
// is days[i] >= endOnDayOf7 
// => for days[4] = 8, end on day 10 (4+7-1)
// => => for 1 day: days[4] = 8, end on day 8
// => => => cost = cost + costs[0]
// => => for 7 day: days[4] = 8, end on day 14 (8 + 7 - 1)
// => => => cost = cost + costs[1]
// => => for 30 day: days[4] = 8, end on day 37 (8 + 30 - 1)
// => => => cost = cost + costs[2]

// for 30 day: days[0] = 1, end on day 30 (1 + 30 - 1)
// days[1] = 4; less than endOnDay for 1 day ticket
// => Would need to buy another
// => for 1 day: days[0] = 1, end on day 1 (1 + 1 - 1)
// stack data structure