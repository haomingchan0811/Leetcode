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
        ret, queue = [], [root]
        for node in queue:
            if node is None:
                ret.append('null')
            else:
                ret.append(str(node.val))
                queue += [node.left, node.right]
        return ','.join(ret)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        vals = data.split(',')
        if len(vals) == 0 or vals[0] == 'null':
            return None
        dummy = root = TreeNode(int(vals[0]))
        queue, i = [root], 1
        for node in queue:
            if node is not None:
                node.left = TreeNode(int(vals[i])) if vals[i] != 'null' else None
                node.right = TreeNode(int(vals[i + 1])) if vals[i + 1] != 'null' else None
                i += 2
                queue += [node.left, node.right]
        return dummy
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))