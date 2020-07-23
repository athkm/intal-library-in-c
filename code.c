#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static char *convert_string(int n)
{
    int length = snprintf(NULL, 0, "%d", n);
    char *str = malloc(length + 1);
    snprintf(str, length + 1, "%d", n);
    return str;
}

static char *rem_lead_zero(char *ch)
{
    while (*ch && *ch == '0')
    {
        ch++;
    }
    char *ch_ = (char *)malloc((strlen(ch) + 1) * sizeof(char));
    strcpy(ch_, ch);
    // free(ch);
    return ch_;
}

static int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

static int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

char *intal_add(const char *intal1, const char *intal2)
{
    int carry = 0;
    int l1 = strlen(intal1);
    int l2 = strlen(intal2);
    int max_len = max(l1, l2);
    char *str = (char *)calloc(max_len + 2, sizeof(char));
    int count1 = 0;
    for (int i = max_len - 1; i >= 0; i--)
    {
        if ((l1 - count1 - 1) >= 0 && (l2 - count1 - 1) >= 0)
        {
            str[i] = (((intal1[l1 - count1 - 1] - '0') + (intal2[l2 - count1 - 1] - '0') + carry) % 10) + '0';
            carry = ((intal1[l1 - count1 - 1] - '0') + (intal2[l2 - count1 - 1] - '0') + carry) / 10;
        }
        else if (l1 > l2)
        {
            str[i] = (((intal1[l1 - count1 - 1] - '0') + carry) % 10) + '0';
            carry = ((intal1[l1 - count1 - 1] - '0') + carry) / 10;
        }
        else if (l2 > l1)
        {
            str[i] = (((intal2[l2 - count1 - 1] - '0') + carry) % 10) + '0';
            carry = ((intal2[l2 - count1 - 1] - '0') + carry) / 10;
        }
        else
        {
            printf("YOU MISSED A CASE LOLOLOL\n");
        }
        count1++;
    }
    if (carry)
    {
        char *ch = (convert_string(carry));
        char *temp = (char *)calloc((strlen(ch) + strlen(str) + 1), sizeof(char));
        strcpy(temp, ch);
        strcat(temp, str);
        free(ch);
        free(str);
        str = temp;
    }
    return str;
}

int intal_compare(const char *intal1, const char *intal2)
{
    if (strlen(intal1) > strlen(intal2))
    {
        return 1;
    }
    else if (strlen(intal1) < strlen(intal2))
    {
        return -1;
    }
    else
    {
        int k = 0;
        while (intal1[k] == intal2[k])
        {
            k++;
            if (k == strlen(intal2))
                return 0;
        }
        if ((intal1[k] - '0') > (intal2[k] - '0'))
            return 1;
        else
        {
            return -1;
        }
    }
}

int intal_max(char **arr, int n)
{
    int res = 0;
    int max_ = 0;
    for (int i = 0; i < n; i++)
    {
        res = intal_compare(arr[i], arr[max_]);
        if (res == 1)
        {
            max_ = i;
        }
    }
    return max_;
}

int intal_min(char **arr, int n)
{
    int res = 0;
    int min_ = 0;
    for (int i = 0; i < n; i++)
    {
        res = intal_compare(arr[i], arr[min_]);
        if (res == -1)
        {
            min_ = i;
            // break;
        }
    }
    return min_;
}

int intal_search(char **arr, int n, const char *key)
{

    int res = 0;
    int search = -1;
    for (int i = 0; i < n; i++)
    {
        res = intal_compare(arr[i], key);
        if (res == 0)
        {
            search = i;
            return search;
            break;
        }
    }
    return search;
}

char *intal_diff(const char *intal1, const char *intal2)
{

    if (intal_compare(intal1, intal2) == 0)
    {
        char *res = (char *)malloc(sizeof(char) * 2);
        res[0] = '0';
        res[1] = '\0';
        return res;
    }
    //assumes string wont start with 0
    int max_len = max(strlen(intal1), strlen(intal2));
    int *num1 = (int *)calloc(max_len, sizeof(int));
    int *num2 = (int *)calloc(max_len, sizeof(int));
    int *total = (int *)calloc(max_len + 1, sizeof(int));
    int flag;

    char *sum = (char *)calloc(max_len, sizeof(char));
    flag = intal_compare(intal1, intal2);
    if (flag == 1)
    {
        int subt = max_len - strlen(intal2);
        for (int i = 0; i < strlen(intal1); i++)
            num1[i] = intal1[i] - '0';

        for (int i = 0; i < strlen(intal2); i++)
            num2[i + subt] = intal2[i] - '0';
    }
    else
    {
        int subt = max_len - strlen(intal1);
        for (int i = 0; i < strlen(intal1); i++)
            num2[i + subt] = intal1[i] - '0';

        for (int i = 0; i < strlen(intal2); i++)
            num1[i] = intal2[i] - '0';
    }
    for (int i = max_len - 1; i >= 0; i--)
    {
        if (num1[i] < num2[i])
        {
            total[i] = num1[i] + 10 - num2[i];
            num1[i - 1] = num1[i - 1] - 1;
        }
        else
            total[i] = num1[i] - num2[i];
        char *ch = (convert_string(total[i]));
        char *temp = (char *)calloc((strlen(ch) + strlen(sum) + 1), sizeof(char));
        strcpy(temp, ch);
        strcat(temp, sum); //prefix copy
        free(sum);
        sum = temp;
        free(ch);
    }
    int count = 0;
    while ((*sum && *sum == '0'))
    {
        count++;
        sum++;
    }
    char *temp = (char *)malloc(sizeof(char) * (strlen(sum) + 1));

    strcpy(temp, sum);
    while (count--)
    {
        // count++;
        sum--;
    }
    free(sum);
    if (strlen(temp) == 0)
    {
        char *res = (char *)malloc(sizeof(char) * 2);
        res[0] = '0';
        res[1] = '\0';
        return res;
    }
    free(num1);
    free(num2);
    free(total);
    return temp;
}

/*
char *intal_diff(const char *intal1, const char *intal2)
{
    if (intal_compare(intal1, intal2) == 0)
    {
        printf("here\n");
        char *res = (char *)malloc(sizeof(char) * 2);
        res[0] = '0';
        res[1] = '\0';
        return res;
    }
    int l1 = strlen(intal1), l2 = strlen(intal2), subt_carry = 0, count1 = 0;
    ;
    int max_len = max(l1, l2);
    char *sum = (char *)calloc(max_len, sizeof(char));
    int flag = intal_compare(intal1, intal2);
    if (flag == 1)
    {
        for (int i = max_len - 1; i >= 0; i--)
        {
            if ((l1 - 1 - count1) >= 0 && (l2 - 1 - count1) >= 0)
            {
                if (((intal1[l1 - 1 - count1] - '0') - subt_carry) < (intal2[l2 - 1 - count1] - '0'))
                {
                    sum[i] = ((intal1[l1 - 1 - count1] - '0') + 10 - (intal2[l2 - 1 - count1] - '0') - subt_carry) + '0';
                    subt_carry = 1;
                }
                else
                {
                    sum[i] = ((intal1[l1 - count1 - 1] - '0') - (intal2[l2 - count1 - 1] - '0') - subt_carry) + '0';
                    subt_carry = 0;
                }
            }
            else
            {
                sum[i] = ((intal1[l1 - count1 - 1] - '0') - subt_carry) + '0';
                subt_carry = 0;
            }
            count1++;
        }
    }
    else
    {
        for (int i = max_len - 1; i >= 0; i--)
        {
            if ((l1 - 1 - count1) >= 0 && (l2 - 1 - count1) >= 0)
            {
                if (((intal2[l2 - count1 - 1] - '0') - subt_carry) < (intal1[l1 - count1 - 1] - '0'))
                {
                    sum[i] = ((intal2[l2 - count1 - 1] - '0') + 10 - (intal1[l1 - count1 - 1] - '0') - subt_carry) + '0';
                    subt_carry = 1;
                }
                else
                {
                    sum[i] = ((intal2[l2 - count1 - 1] - '0') - (intal1[l1 - count1 - 1] - '0') - subt_carry) + '0';
                    subt_carry = 0;
                }
            }
            else
            {
                sum[i] = ((intal2[l2 - count1 - 1] - '0') - subt_carry) + '0';
                subt_carry = 0;
            }
            // sum[i] = total[i] + '0';
            count1++;
        }
    }
    char *temp = rem_lead_zero(sum);
    free(sum);
    if (strlen(temp) == 0)
    {
        temp = "0";
    }
    return temp;
}
*/

char *intal_multiply(const char *intal1, const char *intal2)
{
    int max_len = max(strlen(intal1), strlen(intal2));
    int *num1 = (int *)calloc(max_len, sizeof(int)); //array to hold intal1
    int *num2 = (int *)calloc(max_len, sizeof(int)); //array to hold intal2
    int i, j, temp;
    int *total = (int *)calloc(strlen(intal1) + strlen(intal2) + 1, sizeof(int)); //array to  hold product
    char *sum = (char *)calloc(2 * max_len + 1, sizeof(char));                    //convert total to string
    int l1 = strlen(intal1);
    int l2 = strlen(intal2);
    for (i = l1 - 1, j = 0; i >= 0; i--, j++)
    {
        num1[j] = intal1[i] - '0';
    }
    for (i = l2 - 1, j = 0; i >= 0; i--, j++)
    {
        num2[j] = intal2[i] - '0';
    }
    for (i = 0; i < l2; i++)
    {
        for (j = 0; j < l1; j++)
        {
            total[i + j] += num2[i] * num1[j];
        }
    }
    for (i = 0; i < l1 + l2; i++)
    {
        temp = total[i] / 10;
        total[i] = total[i] % 10;
        total[i + 1] = total[i + 1] + temp;
    }
    for (i = l1 + l2; i >= 0; i--)
    {
        if (total[i] > 0)
            break;
    }
    int c = 0;
    for (; i >= 0; i--)
    {
        int carry = total[i] + '0';
        sum[c++] = carry;
    }

    while ((*sum && *sum == '0'))
    {
        sum++;
    }
    if (strlen(sum) == 0)
    {
        char *res = (char *)malloc(sizeof(char) * 2);
        res[0] = '0';
        res[1] = '\0';
        return res;
    }
    free(num1);
    free(num2);
    free(total);
    return sum;
}

/*
char *intal_mod(const char *intal1, const char *intal2)         //fix binary division and long division for quotient
{
    char *dividend = (char *)calloc(strlen(intal1) + 1, sizeof(char));
    char *remainder = (char *)calloc(strlen(intal1) + 1, sizeof(char));

    if (intal_compare(intal1, intal2) == -1)
    {
        free(dividend);
        free(remainder);
        char *res = (char *)malloc(sizeof(char) * (strlen(intal1) + 1));
        strcpy(res, intal1);
        return res;
    }

    if (strcmp(intal1, intal2) == 0)
    {
        free(dividend);
        free(remainder);
        char *res = (char *)malloc(sizeof(char) * 2);
        res[0] = '0';
        res[1] = '\0';
        return res;
    }

    int len1 = strlen(intal1);
    int intal1_len = len1;
    int len2 = strlen(intal2);
    int i = len2;

    strncat(dividend, intal1, len2);        //dividend of len intal2
    len1 -= len2;

    int flag = 0;
    while (1)
    {
        while (intal_compare(dividend, intal2) == -1)
        {
            if (i == intal1_len)        //reached end of intal1
            {
                int len = strlen(dividend);
                char *r = (char *)malloc(sizeof(char) * (len + 1));

                strcpy(r, dividend);

                free(dividend);
                free(remainder);

                return r;
            }

            if (flag)       //reminder was left 0, so need to copy dividend from beginning
            {
                int copy = i;
                for (; i < copy + strlen(intal2); i++)
                {
                    if (i < strlen(intal1))
                    {
                        strncat(dividend, &intal1[i], 1);
                    }
                    else
                    {
                        free(remainder);
                        return dividend;
                    }
                }
                flag = 0;
            }
            else
            {
                strncat(dividend, &intal1[i++], 1);
                len1--;
            }
        }

        if (intal_compare(dividend, intal2) != 0)
        {
            int cnt = 2;
            int yes = 0;
            char *temp_sub = intal_diff(dividend, intal2);
            if (intal_compare(dividend, intal2) > 0)
            {
                while (intal_compare(temp_sub, intal2) >= 0)        //to find quotient
                {
                    yes = 1;
                    free(temp_sub);
                    char *ch = convert_string(cnt);
                    char *mul = intal_multiply(ch, intal2);
                    temp_sub = intal_diff(dividend, mul);       //subtract by quotient*intal2
                    free(ch);
                    free(mul);
                    cnt++;
                }
            }
            if (yes)
            {
                char *t = intal_add(temp_sub, intal2);
                free(temp_sub);
                temp_sub = t;
            }
            strcpy(remainder, temp_sub);
            free(temp_sub);
            strcpy(dividend, remainder);
        }
        else
        {
            flag = 1;
            memset(dividend, 0, intal1_len + 1);
            if (i == intal1_len)
            {
                free(remainder);
                free(dividend);
                char *res = (char *)malloc(sizeof(char) * 2);
                res[0] = '0';
                res[1] = '\0';
                return res;
            }
        }
    }

    free(dividend);

    int len = strlen(remainder);
    char *r = (char *)malloc(sizeof(char) * (len + 1));
    strcpy(r, remainder);

    free(remainder);

    return r;
}
*/

char *intal_divide(const char *intal1, const char *intal2)
{
    char *dividend = (char *)calloc(strlen(intal1) + 1, sizeof(char));
    char *sum = (char *)calloc(strlen(intal1) + 1, sizeof(char));
    char *remainder = (char *)calloc(strlen(intal1) + 1, sizeof(char));
    if (intal_compare(intal1, intal2) == -1)
    {
        char *res = (char *)malloc(sizeof(char) * 2);
        res[0] = '0';
        res[1] = '\0';
        free(sum);
        free(dividend);
        free(remainder);
        return res;
    }

    if (strcmp(intal1, intal2) == 0)
    {
        char *res = (char *)malloc(sizeof(char) * 2);
        res[0] = '1';
        res[1] = '\0';
        free(sum);
        free(dividend);
        free(remainder);
        return res;
    }
    int len1 = strlen(intal1);
    int intal1_len = len1;
    int len2 = strlen(intal2);
    int i = len2;
    int yes = 0;
    strncat(dividend, intal1, len2);
    len1 -= len2;

    int flag = 0;
    while (1)
    {
        while (intal_compare(dividend, intal2) == -1)

        {
            if (i == intal1_len)

            {
                dividend = rem_lead_zero(dividend);
                int len = strlen(dividend);
                char *r = (char *)malloc(sizeof(char) * (len + 1));

                strcpy(r, dividend);

                free(dividend);
                free(remainder);
                if (yes)

                {
                    char c = '0';

                    strncat(sum, &c, 1);
                }
                return sum;
            }

            if (flag)

            {
                int y2 = 0;
                int copy = i;
                for (; i < copy + strlen(intal2); i++)

                {
                    if (i < strlen(intal1))

                    {
                        strncat(dividend, &intal1[i], 1);
                        if (y2)

                        {
                            char c = '0';

                            strncat(sum, &c, 1);
                        }
                        else
                        {
                            y2 = 1;
                        }
                    }
                    else
                    {
                        char c = '0';

                        strncat(sum, &c, 1);
                        strcpy(remainder, dividend);

                        return sum;
                    }
                }
                flag = 0;
            }
            else
            {
                strncat(dividend, &intal1[i++], 1);
                if (yes)

                {
                    char c = '0';

                    strncat(sum, &c, 1);
                }
                yes = 1;
                len1--;
            }
        }
        yes = 0;
        if (intal_compare(dividend, intal2) != 0) 

        {
            char *str;
            dividend = rem_lead_zero(dividend);
            for (int po = 1; po <= 10; po++)

            {
                int length = snprintf(NULL, 0, "%d", po);
                str = malloc(length + 1);
                snprintf(str, length + 1, "%d", po);
                if (intal_compare(intal_multiply(str, intal2), dividend) > 0)

                {
                    po = po - 1;
                    char c = po + '0';
                    strncat(sum, &c, 1);
                    break;
                }
                else
                {
                    // printf("divisor:%s  dividend:%s\n", intal_multiply(str, intal2), dividend);
                }
            }
            dividend = rem_lead_zero(dividend);
            char *diff1 = intal_diff(str, "1");
            char *mul1 = intal_multiply(intal2, diff1);
            char *temp_sub = intal_diff(dividend, mul1);
            free(diff1);
            free(mul1);
            strcpy(remainder, temp_sub);
            free(temp_sub);
            free(str);
            strcpy(dividend, remainder);
        }
        else 
        {
            flag = 1;
            char c = '1';

            strncat(sum, &c, 1);
            memset(dividend, 0, intal1_len + 1); 
            if (i == intal1_len)

            {
                char *res = (char *)malloc(sizeof(char) * 2);
                res[0] = '0';
                res[1] = '\0';
                return sum;
            }
        }
    }

    free(dividend);
    int len = strlen(remainder);
    char *r = (char *)malloc(sizeof(char) * (len + 1));

    strcpy(r, dividend);

    free(remainder);
    return sum;
}

char *intal_mod(const char *intal1, const char *intal2)
{
    char *val = intal_divide(intal1, intal2);
    char *mul = intal_multiply(intal2, val);
    char *k = intal_diff(intal1, mul);
    free(mul);
    free(val);
    return k;
}

char *intal_pow(const char *intal1, unsigned int n)
{
    if (n == 0)
    {
        char *res = (char *)malloc(sizeof(char) * 2);
        res[0] = '1';
        res[1] = '\0';
        return res;
    }
    char *temp = intal_pow(intal1, n / 2);
    if (n % 2 == 0)
    {
        char *res = intal_multiply(temp, temp);
        free(temp);
        return res;
    }
    else
    {
        char *mul = intal_multiply(temp, temp);
        char *res = intal_multiply(intal1, mul);
        free(temp);
        free(mul);
        return res;
    }
}

char *intal_gcd(const char *intal1, const char *intal2)
{
    char *t1 = (char *)malloc((strlen(intal1) + 1) * sizeof(char));
    strcpy(t1, intal1);
    char *t2 = (char *)malloc((strlen(intal2) + 1) * sizeof(char));
    strcpy(t2, intal2);
    char *temp;
    while (intal_compare(t2, "0") > 0)
    {
        temp = intal_mod(t1, t2);
        free(t1);
        t1 = t2;
        t2 = temp;
    }
    free(t2);
    return t1;
}

char *intal_fibonacci(unsigned int n)
{
    char *str = convert_string(0);
    char *str2 = convert_string(1);
    char *temp;
    temp = intal_add(str, str2);
    free(str2);
    str2 = str;
    str = temp;
    for (int i = n - 1; i > 0; i--)
    {
        temp = intal_add(str, str2);
        free(str2);
        str2 = str;
        str = temp;
    }
    free(str2);
    return str;
}

char *intal_bincoeff(unsigned int n, unsigned int k)
{
    if (k > (n - k))
        k = n - k;
    else
    {
        k = k;
    }

    char **a = (char **)malloc((k + 1) * sizeof(char *));
    for (int i = 0; i <= k; i++)
    {
        a[i] = (char *)malloc(1001 * sizeof(char));
        strcpy(a[i], "0");
    }
    char *temp;
    strcpy(a[0], "1");
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, k); j > 0; j--)
        {
            temp = intal_add(a[j], a[j - 1]);
            free(a[j]);
            a[j] = temp;
        }
    }
    char *p = (char *)malloc(sizeof(char) * (strlen(a[k]) + 1));
    strcpy(p, a[k]);
    for (int i = 0; i < k; i++)
    {
        free(a[i]);
    }
    free(a[k]);
    free(a);
    return p;
}
// TRY BINOMIAL DIVISION

char *intal_factorial(unsigned int n)
{
    char *str = convert_string(n);
    for (int i = n - 1; i > 0; i--)
    {
        char *temp;
        char *str2 = convert_string(i);
        temp = intal_multiply(str, str2);
        free(str2);
        free(str);
        str = temp;
    }

    return str;
}

static void merge(char **arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    char **L = (char **)malloc(sizeof(char *) * n1);
    char **R = (char **)malloc(sizeof(char *) * n2);
    for (i = 0; i < n1; i++)
    {
        L[i] = (char *)malloc(sizeof(char) * (1 + strlen(arr[l + i])));
        strcpy(L[i], arr[l + i]);
        // free(arr[l+i]);
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = (char *)malloc(sizeof(char) * (1 + strlen(arr[m + 1 + j])));
        strcpy(R[j], arr[m + 1 + j]);
        // free(arr[m+1+j]);
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (intal_compare(L[i], R[j]) <= 0)
        {
            // arr[k] = L[i];
            strcpy(arr[k], L[i]);
            i++;
        }
        else
        {
            // arr[k] = R[j];
            strcpy(arr[k], R[j]);
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        // arr[k] = L[i];
        strcpy(arr[k], L[i]);
        i++;
        k++;
    }

    while (j < n2)
    {
        // arr[k] = R[j];
        strcpy(arr[k], R[j]);
        j++;
        k++;
    }

    for (i = 0; i < n1; i++)
    {
        free(L[i]);
    }
    for (j = 0; j < n2; j++)
    {
        free(R[j]);
    }
    free(L);
    free(R);
}

static void mergeSort(char **arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void intal_sort(char **arr, int n)
{
    mergeSort(arr, 0, n - 1);
}

int intal_binsearch(char **arr, int n, const char *key)
{
    intal_sort(arr, n);
    int middle = (n - 1) / 2;
    int first = 0;
    int last = n - 1;
    int ans = -1;
    while (first <= last)
    {
        int num = intal_compare(arr[middle], key);
        if (num == -1)
        {
            first = middle + 1;
        }
        else if (num == 0)
        {
            ans = middle;
            last = middle - 1;
        }
        else
        {
            last = middle - 1;
        }
        middle = (first + last) / 2;
    }
    return ans;
}

char *coin_row_problem(char **arr, int n)
{
    char *currMax = (char *)malloc(2 * sizeof(char));
    char *prevMax = (char *)malloc(2 * sizeof(char));
    strcpy(currMax, "0");
    int flag = 1;
    strcpy(prevMax, "0");
    for (int i = 0; i < n; i++)
    {
        char *cur = arr[i];
        char *nmax = (char *)malloc(sizeof(char));
        char *add_ = intal_add(prevMax, cur);
        if (intal_compare(currMax, add_) == 1)
        {
            free(nmax);
            nmax = currMax;
            free(add_);
        }
        else
        {
            free(nmax);
            nmax = add_;
        }
        prevMax = currMax;
        currMax = nmax;
    }
    return currMax;
}
