def excitement_level(message):
    bb_count = 0
    ee_count = 0
    for i in range(len(message) - 1):
        if message[i:i+2] == 'BB':
            bb_count += 1
        elif message[i:i+2] == 'EE':
            ee_count += 1
    return bb_count + ee_count

def generate_messages(message, i, possible_messages):
    if i == len(message):
        possible_messages.add(excitement_level(message))
    elif message[i] == 'F':
        message = message[:i] + 'B' + message[i+1:]
        generate_messages(message, i+1, possible_messages)
        message = message[:i] + 'E' + message[i+1:]
        generate_messages(message, i+1, possible_messages)
    else:
        generate_messages(message, i+1, possible_messages)

n = int(input())
message = input()
possible_messages = set()
generate_messages(message, 0, possible_messages)
excitement_levels = sorted(possible_messages)
print(len(excitement_levels))
for level in excitement_levels:
    print(level)
