[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2019a)

# T3: Scheduling com OpenMP
Nome:Gabriela Luisa Eckel
[Código](OpenMPDemoABD.cpp)

### Saídas 
**STATIC**
```
Caso 1.0 sem usar o CRITICAL, espera-se erro.
        shedule_type: omp_sched_static, chunk_size:
ACABCACBACBCABCCABCABCACBCABCABCACBCABCBACBACBACBA-BABABABA-
A=20 B=19 C=19
```
```
Caso 1.1, usando o CRITICAL e sem a especificação do chunk = nTimes
        shedule_type: omp_sched_static, chunk_size:
CABAAABABCBCCBABCBBBCBCACBCBABBACACBCCCACBAACAAAAAAACBCCBCBB
A=20 B=20 C=20
```
```
 Caso 1.2, usando o CRITICAL e chunk = 1
        shedule_type: omp_sched_static, chunk_size:
CACABACACACAABABABCBCACBCBABACBACBCACBCBCACACACABACBCABBBBBB
A=20 B=20 C=20
```
------------------------------------
**DYNAMIC**

```
Caso 2.0 sem usar o CRITICAL, espera-se erro.
        shedule_type: omp_sched_dynamic, chunk_size:
ABACCABCABCABCABCABCABCABCACBACACACCACACABCACACA-A-BBBBBBBBB
A=20 B=19 C=19
```
```
Caso 2.1, usando o CRITICAL e sem a especificação do chunk = nTimes
        shedule_type: omp_sched_dynamic, chunk_size:
BACBABABAABACBABAABABACABABBABBABCACBBACBACBAACCBCCCCCCCCCCC
A=20 B=20 C=20
```
```
Caso 2.2, usando o CRITICAL e chunk = 1
        shedule_type: omp_sched_dynamic, chunk_size:  (default)
CBABACBABABABABABACABCBABABABABCBABABCBABACACABCBACBACABCBAC
A=23 B=24 C=13
```
------------------------------------
**GUIDED**
```
Caso 3.0 sem usar o CRITICAL, espera-se erro.
        shedule_type: omp_sched_guided, chunk_size:
BACACBACBACBACABCABCABCABCABCABCABCABABCABCABCABCABCBAC--C--
A=19 B=18 C=19
```
```
Caso 3.1, usando o CRITICAL e sem a especificação do chunk = nTimes
        shedule_type: omp_sched_guided, chunk_size:
ABABABBABABBAABCBCBBAABBBABACABABAAABACBABCAACCCCCCCCCCCCCCC
A=20 B=20 C=20
```
```
Caso 3.2, usando o CRITICAL e chunk = 1
        shedule_type: omp_sched_guided, chunk_size:  (default)
BABBBCBABACBCBCBCBAACBCBCBCABAAAAAAACBABCBBBBACAAABABABACCBC
A=21 B=24 C=15
```
------------------------------------
**AUTO**
```
Caso 5.0 sem usar o CRITICAL, espera-se erro.
        shedule_type: omp_sched_auto, chunk_size:
BBCBCABCBACBACBCABCBACBACBCBCBABCABCABCABCBACBCBCA-CA-AAAAAA
A=19 B=20 C=19
```
```
Caso 5.1, usando o CRITICAL e sem a especificação do chunk = nTimes
        shedule_type: omp_sched_auto, chunk_size:
BACABCBACABCBCBABCBBCBABCACBAAABACACBABCBBBABAACACBAAACCCCCC
A=20 B=20 C=20
```
```
Caso 5.2, usando o CRITICAL e chunk = 1
        shedule_type: omp_sched_auto, chunk_size:  (default)
BABABCBCCAACACBCBCACCBCBACACAAACAAACACBABCCCCCAABABABBBBBBBB
A=20 B=20 C=20
```
