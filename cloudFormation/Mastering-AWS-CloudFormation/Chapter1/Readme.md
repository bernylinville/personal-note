# Chapter1

create this stack for the service role and obtain the CloudFormation role ARN:

```bash
aws cloudformation create-stack \
                   --stack-name cfniamrole \
                   --capabilities CAPABILITY_IAM \
                   --template-body file://CfnIamRole.yml

IAM_ROLE_ARN=$(aws cloudformation describe-stacks \
                                  --stack-name cfniamrole \
                                  --query "Stacks[0].Outputs[?OutputKey=='IamRole'].OutputValue" \
                                  --output text)
```

run the creation of the stack, which will use our role, specifying the Role ARN:

```bash
aws cloudformation create-stack --stack-name mybucket \
                                --template-body file://MyBucket.yaml \
                                --role-arn $IAM_ROLE_ARN
```

clean test

```bash
for i in mybucket iamrole cfniamrole; do aws cloudformation delete-stack --stack-name $i ; done
```
