def get_UnorderedGroupChildren(self):
    """
    List all non-metadata children of an UnorderedGroup
    """
    # TODO: should not change order
    return self.get_RegionRef() + self.get_OrderedGroup() + self.get_UnorderedGroup()

