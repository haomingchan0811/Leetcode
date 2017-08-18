# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    
    def serialize(self, root):
        """Encodes a tree to a single string.
        :type root: TreeNode
        :rtype: str
        """
        queue = [root]
        ret = ''
        for node in queue:
            if node is None:
                ret += ('' if ret == '' else ',') + 'null'
            else:
                ret += ('' if ret == '' else ',') + str(node.val)
                queue += [node.left, node.right]
        return ret
        
    
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        :type data: str
        :rtype: TreeNode
        """
        data = data.split(',')
        if data == [] or data[0] == 'null':
            return None
        root = TreeNode(int(data[0]))
        dummy = root
        queue, i = [root], 1
        for node in queue:
            if node is not None:
                node.left = TreeNode(int(data[i])) if data[i] != 'null' else None
                node.right = TreeNode(int(data[i + 1])) if data[i + 1] != 'null' else None
                queue += [node.left, node.right]
                i += 2
        return dummy


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))