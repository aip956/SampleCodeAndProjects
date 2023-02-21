def convert(input)
    output = ""
    romans = {
        1000 => "M",
        900 => "CM",
        500 => "D",
        400 => "CD",
        100 => "C",
        90 => "XC",
        50 => "L",
        40 => "XL",
        10 => "X",
        9 => "IX",
        5 => "V",
        4 => "IV",
        1 => "I",
    }
    romans.each do |value, symbol|
        while input >= value
            output += symbol
            input -= value
        end
    end
output
end

puts(convert(14))
#XIV
puts(convert(79))
#LXXIX
puts(convert(845))
puts(convert(2022))
# num = input = 1990
#floor (num / key) = mult
# = floor 1990 / 1000 = 1
# push mult * value = 1 * M
# { M}
# num = num % key = 1990 % 1000 = 990
#floor (num / key) = mult
# = floor 990 / 900 = 1
# push mult * value = 1 * CM
# { MCM}
# num = num % key = 990
#floor (num / key) = mult
# = floor 990 / 900 = 1
# push mult * value


