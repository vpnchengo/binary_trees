#include "binary_trees.h"

/**
 * binary_tree_is_perfect - a function that checks if binary tree is perfect
 * @tree: a pointer to the root to the root node of the tree to check
 * Return: 1 if binary tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if ((binary_tree_is_full(tree) == 1) &&
			(binary_tree_balance(tree) == 0))
		return (1);
	return (0);
}

/**
 * binary_tree_is_full - a function that checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is full or 0 if tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left && tree->right)
	{
		return ((binary_tree_is_full(tree->left)) &&
				(binary_tree_is_full(tree->right)));
	}
	return (0);
}

/**
 * binary_tree_balance - A function that measures the balance factor of a
 * binary tree
 * @tree: Pointer to root node of the tree to measure balance factor.
 * Return: (int) The balance factor of the tree
 * return 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	return (left_height - right_height);
}

/**
 * binary_tree_height - a function that measures the height of a binary tree
 * @tree: a pointer to the root node of the tree
 * to measure the height
 * Return: (size_t) height, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_size = 0;
	size_t right_size = 0;

	if (!tree)
		return (0);

	left_size += 1 + binary_tree_height(tree->left);
	right_size += 1 + binary_tree_height(tree->right);
	if (left_size > right_size)
		return (left_size);

	return (right_size);
}
