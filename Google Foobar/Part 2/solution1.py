def solution(h, q):
    answer = []
    size = 2**h - 1

    for idx in q:
        if size < idx:
            return -1

        else:
            node_offset = 0
            continue_flag = True
            subtree_size = size
            result = -1
            
            while continue_flag:
                if subtree_size == 0:
                    continue_flag = False

                subtree_size = subtree_size >> 1

                left_node = node_offset + subtree_size
                right_node = left_node + subtree_size

                node = right_node + 1

                if (left_node == idx) or (right_node == idx):
                    result = node
                    continue_flag = False

                if (idx > left_node):
                    node_offset = left_node
    
            answer.append(result)
    return answer