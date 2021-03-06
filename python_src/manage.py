from argparse import ArgumentParser
from unittest import TestLoader, runner
from estrutura_dados import pilha_fila
from estrutura_dados import index
from estrutura_dados import tarefa_1
from estrutura_dados import tarefa_2

parser = ArgumentParser(prog='Manage')

parser.add_argument(
    'mode',
    type=str,
    help='Modo de execução (runserver|tests)'
)

args = parser.parse_args()


def tests():
    loader = TestLoader()
    tests = loader.discover('tests/')
    testRunner = runner.TextTestRunner()
    testRunner.run(tests)


modes = {
    'tests': tests,
    'structs': pilha_fila.main,
    'algorithms': index.main,
    'tarefa_1': tarefa_1.main,
    'tarefa_2': tarefa_2.main
}[args.mode]()
