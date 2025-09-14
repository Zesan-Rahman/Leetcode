# @param {String} s
# @return {Integer}
def max_freq_sum(s)
    table = Hash.new
    table.default = 0
    vowel_count = 0
    consonant_count = 0
    s.each_char do |char|
        table[char] += 1
        if "aeiou".include?(char) then vowel_count =[vowel_count, table[char]].max
        else consonant_count = [consonant_count, table[char]].max end
    end
    consonant_count + vowel_count
end