


#### 求给定一棵二叉树的深度

遍历树中每个节点，当前节点的深度表示为：1+max{左子树的深度，右子树的深度}


#### 判断给定一棵二叉树是否为平衡树

平衡树的定义为：树中任意节点的左右子树深度相差不超过１


根据求二叉树的深度，可以求出任意节点左右子树的深度，如果其差值都不大于１，则为平衡二叉树。

但是，此法会做过多的重复计算。改进后的方法，采用后序遍历的方式：在递归回溯的时候，将某节点的深度同时回传。如此避免了重复计算子树深度。

