a = ['magazino', '#toru', '#soto', 'eae']

def filter_strings(strings):
    result = [s for s in strings if s.startswith('#')]
    return result


