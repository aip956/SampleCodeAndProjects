var shortestToChar = function(s, c) {
    let i = 0;
    const pos_array = [];
    const answer = [];
	while (i < s.length) {
		if (s[i] == c) {
        pos_array.push(i);
        };
	i++;	
	};

    for (i = 0; i < s.length; i++) {
        const diff_array = [];
        for (j = 0; j < pos_array.length; j++) {
            diff = (Math.abs(i - pos_array[j]));
            diff_array.push(diff);
            };
        min = (Math.min(...diff_array));
        answer.push(min);
        };
  return answer;
}
