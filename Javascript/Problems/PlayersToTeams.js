/**
 * @param {number[]} skill
 * @return {number}
 */

// https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/


 var dividePlayers = function(skill) {
    console.log(skill);
    total_sum = 0;


    team_sum = 0;
    i = 0;
    
    chemistry = 0;
    total_chem = 0;
    for (i = 0; i < skill.length; i++) {
        total_sum += skill[i];
    };
    console.log("Total sum: ", total_sum);
    num_teams = skill.length / 2;
    console.log("Num_Teams: ", num_teams);
    team_sum = total_sum / num_teams;
    console.log("Team Sum :", team_sum);
    if (total_sum % num_teams != 0) {
        console.log("Error; can't split teams");
        return -1;
    }
    skill.sort(function(a, b) {return a - b});





    console.log("After sort: ", skill);
while (skill.length > 0) {
    console.log("First: ", skill[0]);
    console.log("Last: ", skill[skill.length-1]);
    if (skill[0] + skill[skill.length-1] != team_sum) {
        return -1;
    }
        chemistry = skill[0] * skill[skill.length-1];
        console.log("Chem: ", chemistry);
        total_chem += chemistry;
        console.log("Total_chem: ", total_chem);
        skill.pop();
        skill.shift();
        console.log("Skill after: ", skill);

}
console.log("Total chem: ", total_chem);
return total_chem;

};

// console.log(dividePlayers([3,2,5,1,3,4]));
// console.log(dividePlayers([3,4]));
// console.log(dividePlayers([1,1,2,3]));
// console.log(dividePlayers([2,4,1,3]));
// console.log(dividePlayers([2,1,5,2]));
// console.log(dividePlayers([13,1,14,3,2,15]));
console.log(dividePlayers([14,16,17,10,6,12,9,20]));

/*
valid in the loop; team_sum = player sum
balance sum = sum of array / num of teams in array
and number of teams
if sum is not balance sum //
1,2,3,4
sum is 10
2 teams = length / 2
team sum : 10 / 2 = 5 = sum / num_teams

*/
