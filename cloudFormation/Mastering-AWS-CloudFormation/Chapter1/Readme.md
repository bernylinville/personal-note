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

questions:
1. Which API method is invoked when we create a CloudFormation stack?
cloudformation:CreateStack

2. What is a CloudFormation service role?
CloudFormation supports service roles. Service roles are the IAM roles that are used by different AWS services (such as EC2, ECS, Lambda, and so on). CloudFormation service roles are used by CloudFormation during stacks and StackSets operations—creation, update, and deletion.

3. Which IAM policies are used if we do not specify the CloudFormation service role?
AdminPolicy

4. How is the information about stack resources stored in CloudFormation?
5. What happens if we delete the resource created by CloudFormation and try to create the same stack?
It will create again.

6. What happens if we delete the resource created by CloudFormation and try to update the same stack?
Stack [stack-name] does not exist.

7. Why can't CloudFormation recreate the deleted resource?
